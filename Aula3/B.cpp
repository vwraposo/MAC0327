#include <cstdio>
#include <cstring>
#include <cmath>
#define MAX 100000

using namespace std;

int v[MAX + 5];
long long ans[MAX + 5];

void sieve () {
    for (int i = 2; i <= MAX; i++) {
        if (!v[i])   
            for (int j = i; j <= MAX; j+=i)
                v[j] = i;
    }
}

long long phi (int x) {
    if (x == 1) return 1;
    long long ans = 1;
    while (x > 1) {
        int n = 1;
        int p = v[x];
        int next = x / p;
        while (next != 1 && v[next] == p) {
            n++;
            x = next;
            next = next / p;
        }
        x = next;
        ans *= (pow (p, n) - pow (p, n-1)); 
    }

    return ans;
}
int main () {
    sieve ();
    // Precalculations
    ans[1] = 1 - phi (1);
    for (int i = 2; i <= MAX; i++) {
        ans[i] = ans[i-1] + (i - phi (i));
    }
    int T; 
    scanf ("%d", &T);
    for (int i = 1; i <= T; i++) {
        int N; 
        scanf ("%d", &N);
        printf ("Case %d: %lld\n", i, ans[N]);
    }

    return 0;
}
