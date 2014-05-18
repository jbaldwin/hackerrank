#include <stdio.h>
#include <stdbool.h>

#define MAX_FIB 10000000000

int fill_fib(
    unsigned long long fib[], 
    unsigned long long max_fib) {
    
    unsigned long long last = 0;
    unsigned long long curr = 1;
    int i = 2;
    
    fib[0] = last;
    fib[1] = curr;
    
    while(curr < max_fib) {
        unsigned long long t = curr;
        curr = last + curr;
        last = t;
        
        fib[i] = curr;
        i++;
    }
    
    return i;
}

int main(int argc, char* argv[]) {
    
    unsigned long long fib[64]; // test show 51 fibs possible
    int fib_count = fill_fib(fib, MAX_FIB);
    
    int t;
    scanf("%i", &t);
    while(t--) {
        unsigned long long n;
        scanf("%llu", &n);
        
        bool isFibo = false;
        for(int i = 0; i < fib_count; i++) {
            if(n == fib[i]) {
                isFibo = true;
                break;
            }
        }
        
        printf("%s\n", (isFibo) ? "IsFibo" : "IsNotFibo");
    }
    
    return 0;
}
