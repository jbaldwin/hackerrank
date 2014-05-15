#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {
    int N = -1;
    fscanf(stdin, "%i", &N);
    if(N > 100) return -1;
    if(N < 1)   return -2;
    
    int gems[26];
    memset(gems, 0, 26 * sizeof(int));
    
    for(int i = 0; i < N; i++) {
        char comp[101]; // 101 for null char
        memset(comp, '\0', 101);
        fscanf(stdin, "%s", comp);
        
        bool gems_found[26];
        memset(gems_found, false, sizeof(bool) * 26);
        
        int len = strlen(comp);
        for(int j = 0; j < len; j++) {
            // we don't really care exactly just as
            // long as they map to the same spot
            gems_found[comp[j] % 26] = true;
        }
        
        for(int j = 0; j < 26; j++) {
            if(gems_found[j]) {
                gems[j]++;
            }
        }
    }
    
    int gem_count = 0;
    for(int i = 0; i < 26; i++) {
        if(gems[i] == N) {
            gem_count++;
        }
    }
    
    printf("%i\n", gem_count);
   
    return 0;
}