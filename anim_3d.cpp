#include <stdio.h>
#include <unistd.h>

const char rocket[] = 
"           _\n\
          /^\\\n\
          |-|\n\
          | |\n\
          |N|\n\
          |A|\n\
          |S|\n\
          |A|\n\
         /| |\\\n\
        / | | \\\n\
       |  | |  |\n\
        `-\"\"\"-`\n\
";

int main() {
    for (int i = 0; i < 50; i ++) printf("\n");
    printf("%s", rocket);
    int j = 300000;
    for (int i = 0; i < 50; i ++) {
        usleep(j);
        j = (int) (j*0.9);
        printf("\n");
    }
    printf(":))!\n");
    return 0;
}

