#include <stdio.h>
#include <stdbool.h>

void printfr(int repeat, char* str) {
    while(repeat--) {
        printf("%s", str);
    }
}

int main(int argc, char* argv[]) {
    int t;
    scanf("%i", &t);
    while(t--) {
        int n;
        scanf("%i", &n);

        bool found = false;
        for(int i = n; i >= 0; i--) {
            
            if(i % 3 == 0 && (n - i) % 5 == 0) {
                printfr(i / 3,       "555");
                printfr((n - i) / 5, "33333");
                found = true;
                break;
            }
        }
        
        if(!found) {
            printf("-1");
        }
        if(t) {
            printf("\n");
        }
    }
    
    return 0;
}
