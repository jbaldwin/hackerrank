#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_FIB 10000000000

int fill_fib(
    uint64_t fib[],
    uint64_t max_fib
) {

    uint64_t last = 0;
    uint64_t curr = 1;
    int i = 2;

    fib[0] = last;
    fib[1] = curr;

    while(curr < max_fib) {
        uint64_t t = curr;
        curr = last + curr;
        last = t;

        fib[i] = curr;
        i++;
    }

    return i;
}

int main(int argc, char* argv[]) {

    uint64_t fib[64]; // test show 51 fibs possible
    int32_t fib_count = fill_fib(fib, MAX_FIB);

    int32_t t;
    scanf("%i", &t);
    while(t--) {
        uint64_t n;
        scanf("%llu", &n);

        bool isFibo = false;
        for(int32_t i = 0; i < fib_count; i++) {
            if(n == fib[i]) {
                isFibo = true;
                break;
            }
        }

        printf("%s\n", (isFibo) ? "IsFibo" : "IsNotFibo");
    }

    return 0;
}
