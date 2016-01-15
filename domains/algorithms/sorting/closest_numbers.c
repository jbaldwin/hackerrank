#include <stdio.h>
#include <stdlib.h>

int sorter(const void* pa, const void* pb) {
    int a = *(int*)pa;
    int b = *(int*)pb;
    
    if(a < b) return -1;
    if(b < a) return 1;
    return 0;
}

int main(int argc, char* argv[]) {
    int N;
    scanf("%i", &N);
    
    int input[N];
    for(int i = 0; i < N; i++) {
        scanf("%i", &input[i]);
    }
    
    qsort(input, N, sizeof(int), sorter);
    
    int min_diff = 20000000;
    int pairs[N][2];
    int pair_count = 0;
    for(int i = 0; i < N - 1; i++) {
        int diff = input[i + 1] - input[i];
        if(diff < min_diff) {
            min_diff = diff;
            pairs[0][0] = input[i];
            pairs[0][1] = input[i + 1];
            pair_count = 1;
        } else if(diff == min_diff) {
            pairs[pair_count][0] = input[i];
            pairs[pair_count][1] = input[i + 1];
            pair_count++;
        }
    }
    
    printf("%i %i", pairs[0][0], pairs[0][1]);
    for(int i = 1; i < pair_count; i++) {
        printf(" %i %i", pairs[i][0], pairs[i][1]);
    }
    
    return 0;
}