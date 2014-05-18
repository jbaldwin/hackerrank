#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100000
#define MAX_VAL 1000000001

inline int min(int a, int b) {
    return (a < b) ? a : b;
}

inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int sorter(const void* pa, const void* pb) {
    int a = *(int*)pa;
    int b = *(int*)pb;
    
    if(a > b) return 1;
    if(b > a) return -1;
    return 0;
}
 
int main() {
    int N;
    int K;
	int candies[MAX];
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++) {
        scanf("%d", candies + i);
    }
    
    // Sort the candies input so we can make a single pass
    // through the data instead of multiple
    qsort(candies, N, sizeof(int), sorter);
  
    int unfairness = MAX_VAL;
    for(int i = 0; i < N - K; i++) {
        int u_max = 0;
        int u_min = MAX_VAL;
        
        for(int j = 0; j < K; j++) {
            u_max = max(u_max, candies[i + j]);
            u_min = min(u_min, candies[i + j]);
        }
        
        int u = u_max - u_min;
        if(u <= unfairness) {
            unfairness = u;
        }
    }
        
    printf("%d", unfairness);
    return 0;
}
