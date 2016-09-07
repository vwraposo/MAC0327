#include <cstdio>
#define MAX 10000

using namespace std;

int v[MAX + 5];
int p[MAX+5];

int main () {
    // Crivo de erastoteles para achar um primo muliplo do numero 
    for (int i = 2; i <= MAX; i++) 
        if (!v[i])
            for (int j = i; j <= MAX; j+=i)
                v[j] = i;

    int ans = 1;
    int maxP = 0;
    for (int i = 0; i < 10; i++) {
        int a;
        scanf ("%d", &a);
        while (a > 1) {
            //printf ("a %d div a: %d\n", a, v[a]);
            p[v[a]]++;
            a /= v[a];
        }
    }
    for (int i = 0; i <= MAX; i++) {
        if (p[i] != 0) {
            //printf ("AQUI %d\n", p[i]);
            ans *= (p[i] + 1) % 10;
            ans %= 10;
        }
    }

    printf ("%d\n", ans);

    return 0;
}
