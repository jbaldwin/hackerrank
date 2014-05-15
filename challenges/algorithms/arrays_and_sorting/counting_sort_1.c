#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int N;
    fscanf(stdin, "%i\n", &N);
    
    int count[100];
    memset(count, 0, sizeof(int) * 100);
    
    for(int i = 0; i < N; i++) {
        int num;
        fscanf(stdin, "%i", &num);
        count[num]++;
    }
    
    for(int i = 0; i < 100; i++) {
        printf("%i ", count[i]);
    }
    
    return 0;
}