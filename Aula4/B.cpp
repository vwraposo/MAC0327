#include <cstdio>
#include <algorithm>
#include <climits>
#define MAX 1000000

using namespace std;

int c[MAX + 5];
long long memo[MAX+5][MAX+5];

void crivo () {
    for (int i = 2; i < MAX; i++)
        if (!c[i])
            for (int j = i; j < MAX; j += i)
                c[j] = i;
}

int p (int n) {
    if (n == 1) return 0;
    if (n == c[n]) return -1;
    int On = 0;
    while (n > 1) {
        n = n / c[n];
        On++;
    } 
    return On;
}

long long maxFi (int L, int U) {
    if (L > U) return LONG_MIN;
    if (memo[L][U] != 0) return memo[L][U];
    int r1 = maxFi (L+1, U);
    int r2 = maxFi (L, U-1);

    printf ("%d %d:%d %d\n", L, U, r1, r2);
    return memo[L][U] = max (r1, r2);
}

int main () {
    crivo ();
    for (int i = 1; ; i++) {
        int L, U;
        scanf ("%d %d", &L, &U);
        if (L == -1) break;
        long long ans = maxFi (L, U);
        printf ("%d. %lld\n", i, ans);
    }

    return 0;
}
