#include <stdio.h>

int main(int argc, char* argv[]) {
    int N = -1;
    int T = -1;
    fscanf(stdin, "%i %i\n", &N, &T);

    // Read highway data
    int width[N];
    for(int i = 0; i < N; i++) {
        fscanf(stdin, "%i", &width[i]);
    }

    // Read test case data
    int tests[T][2];
    for(int i = 0; i < T; i++) {
        fscanf(stdin, "%i %i\n", &tests[i][0], &tests[i][1]);
    }

    // Execute each test case
    for(int i = 0; i < T; i++) {
        int start = tests[i][0];
        int stop  = tests[i][1];
        int min_width = 3;
        for(int j = start; j <= stop; j++) {
            min_width = (min_width < width[j]) ? min_width : width[j];
        }
        
        printf("%i\n", min_width);
    }
    
    return 0;
}