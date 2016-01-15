#include <stdio.h>

int main(int argc, char* argv[]) {
    int n, m;
    scanf("%i%i", &n, &m);
    
    unsigned long long candies = 0;
    while(m--) {
        unsigned long long a, b, k;
        scanf("%llu%llu%llu", &a, &b, &k);
        candies += (b - a + 1) * k;
    }
    
    printf("%llu\n", candies / n);
    
    return 0;
}
