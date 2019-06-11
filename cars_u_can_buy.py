
car_names = ["Deveste eight", "Vamos", "Deviant", "Schlagen GT", "Tulip", "Itali GTO", "Toros", "Neon", "Entity XXR", 
"Flash GT"]
car_prices = [1795000, 596000, 512000, 1300000, 718000, 1965000, 498000, 1500000, 2305000, 1675000]

cars_u_can_buy = []

def cars_buy(max_price):
    for prices in car_prices:
        if max_price <= prices:
            cars_u_can_buy.append(car_names[:1])
    return cars_u_can_buy
    
print(cars_buy(1000000))