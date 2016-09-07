#include <cstdio>

using namespace std;

int p[10005];
int N, max = 0;

int main () {
    scanf ("%d", &N);
    for (int i = N; i > 1; i--) {
        int n = i;
        int fator = 2;
        while (n > 1) {
            while (n % fator == 0) {
                n /= fator;
                p[fator]++;
                if (fator > max) max = fator;
            }
            fator++;
        }
    }
    for (int i = 2; i < max; i++) {
        if (p[i] != 0)
            printf ("%d^%d * ", i, p[i]); 
    }
    printf ("%d^%d\n", max, p[max]); 

    return 0;
}


