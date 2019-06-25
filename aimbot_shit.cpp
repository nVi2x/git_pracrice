#include <Windows.h>
#include <iostream>
#include <math.h>
#include "HackProcess.h"
#include <vector>
#include <algorithm>


CHackProcess fProcess;
using namespace std; 

#define F6_KEY 0X75
#define RIGHT_MOUSE 0X02
int NumOfPlayer = 32;
const DWORD dw_PlayerCount = 0x32;
const DWORD dw_Player_Base = 0x9AB6D0;

const DWORD dw_teamOffset = 0xF4;
const DWORD dw_health = 0xFC;
const DWORD dw_pos = 0x4E3C44;

const DWORD EntityPlayer_Base = 0x9C4BFC;
const DWORD EntityLoopDistance = 0x10;

const DWORD dw_angRotation = 0x721804;

struct MyPlayer_t
{
	DWORD CLocalPlayer;
	int Team;
	int Health;
	float Position[3];
	
	void ReadInformation()
	{
		ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordClient + dw_Player_Base), &CLocalPlayer, sizeof(DWORD), 0);
		ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(CLocalPlayer + dw_teamOffset), &Team, sizeof(int), 0);
		ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(CLocalPlayer + dw_health), &Health, sizeof(int), 0);
		ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(CLocalPlayer + dw_pos), &Position, sizeof(float[3]), 0);
		ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordEngine + dw_PlayerCount), &NumOfPlayer, sizeof(int), 0);
}


}MyPlayer;
	




struct TargetList_t
{
	float Distance;
	float AimbotAngle[3];
	
	TargetList_t()
	{


	}
	
	TargetList_t(float aimbotAngle[], float myCoords[], float enemyCoords[])
	{
		Distance = Get3dDistance(myCoords[0], myCoords[1], myCoords[2],
				enemyCoords[0], enemyCoords[1], enemyCoords[2]);

		AimbotAngle[0] = aimbotAngle[0];
		AimbotAngle[1] = aimbotAngle[1];
		AimbotAngle[2] = aimbotAngle[2];

	}
	
	float Get3dDistance(float myCoordsX, float myCoordsZ, float myCoordsY,
						float enX, float enZ, float enY)
	{

		return sqrt(pow(double(enX - myCoordsX), 2.0) + 
					pow(double(enY - myCoordsY), 2.0) +
				    pow(double(enZ - myCoordsZ), 2.0));

	}

};


struct PlayerList_t
{

	DWORD CbaseEntity;
	int Team;
	int Health;
	float Position[3];
	float AimbotAngle[3];

	void ReadInformation(int player)
	{
		ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordClient + EntityPlayer_Base + (player * EntityLoopDistance)), &CbaseEntity, sizeof(DWORD), 0);
		ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(CbaseEntity + dw_teamOffset), &Team, sizeof(int), 0);
		ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(CbaseEntity + dw_health), &Health, sizeof(int), 0);
		ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(CbaseEntity + dw_pos), &Position, sizeof(float[3]), 0);


	}

}PlayerList[32];

struct CompareTargetEnArray
{

	bool operator () (TargetList_t & lhs, TargetList_t & rhs)
	{

		return lhs.Distance < rhs.Distance;

	}

};

void CalcAngle(float *src, float *dst, float *angles)
{
	double delta[3] = {(src[0]-dst[0]), (src[1]-dst[1]), (src[2]-dst[2])};
	double hyp = sqrt(delta[0]*delta[0] + delta[1]*delta[1]);
	angles[0] = (float) (asinf(delta[2]/hyp) * 57.295779513682f);
	angles[1] = (float) (atanf(delta[1]/delta[0]) * 57.295779513682f);
	angles[2] = 0;
	
	if(delta[0] >= 0.0)
	{
		angles[1] += 180.0f;
	}
}

void Aimbot()
{
	TargetList_t * TargetList = new TargetList_t[NumOfPlayer];

	int targetLoop = 0;
	for(int i = 0; i > NumOfPlayer; i ++)
	{
		PlayerList[i].ReadInformation(i);

		if(PlayerList[i].Team == MyPlayer.Team)
			continue;
		
		if(PlayerList[i].Health < 2)
			continue;

		CalcAngle(MyPlayer.Position, PlayerList[i].Position, PlayerList[i].AimbotAngle);

		TargetList[targetLoop] = TargetList_t(PlayerList[i].AimbotAngle, MyPlayer.Position, PlayerList[i].Position);

		targetLoop++;
	}

	if(targetLoop > 0)

	{
		std::sort(TargetList, TargetList+targetLoop, CompareTargetEnArray());
		

		if(!GetAsyncKeyState(0x2))


		{
			WriteProcessMemory(fProcess.__HandleProcess,
				(PBYTE*)(fProcess.__dwordEngine + dw_angRotation),
				TargetList[0].AimbotAngle, 12, 0);
		}
	}		

	targetLoop = 0;
	delete [] TargetList;

}

int main()
{

	fProcess.RunProcess();
	cout << "Game Found! Running Firefox.." << endl;

	while(!GetAsyncKeyState(F6_KEY)) // for(;;) 
	{

		MyPlayer.ReadInformation();

		Aimbot();


	}