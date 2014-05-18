#include <stdio.h>

int main() {
    int t, n, c, m;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &c, &m);
        
        int answer = n / c;
        int wrappers = answer;
        
        while(wrappers >= m) {
            answer++;
            wrappers -= (m - 1);
        }

        printf("%d\n", answer);
    }
    return 0;
}
