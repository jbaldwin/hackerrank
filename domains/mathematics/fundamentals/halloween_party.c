#include <stdio.h>

int main(int argc, char* argv[]) {
    int T;
    scanf("%i", &T);
    
    for(int i = 0; i < T; i++) {
        unsigned long K;
        scanf("%lu", &K);
        
        unsigned long pieces;
        if(K % 2 == 0) {
            pieces = (K / 2) * (K / 2);
        } else {
            pieces = (K / 2) * (K / 2 + 1);
        }
        
        printf("%lu\n", pieces);
    }
    
    return 0;
}