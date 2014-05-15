#include <stdio.h>

int main(int argc, char* argv[]) {
    int len = -1;
    scanf("%i\n", &len);
    
    if(len > 10) len = 10;
    
    for(int i = 0; i < len; i++) {
        int height = 1;
        int cycles = -1;
        scanf("%i\n", &cycles);
        if(cycles > 60) cycles = 60;
        for(int c = 0; c < cycles; c++) {
            height = (c % 2 == 1) ? height + 1 : height * 2;
        }
        
        printf("%i\n", height);
    }

    return 0;
}