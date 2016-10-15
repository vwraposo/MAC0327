#include <bits/stdc++.h>

using namespace std;

const int MAX = 2005;
int memo[MAX][MAX];
int s, n, size[MAX], value[MAX];

int dp (int obj, int w) {
    if (obj == n) return 0;
    if (memo[obj][w] != -1) return memo[obj][w];
    if (size[obj] <= w) {
        memo[obj][w] = max (value[obj] + dp (obj+1, w - size[obj]), dp (obj+1, w));
    }
    else 
        memo[obj][w] = dp (obj+1, w);

    return memo[obj][w];
}

int main () {
    scanf ("%d %d", &s, &n);
    for (int i = 0; i < n; i++) 
        scanf ("%d %d", &size[i], &value[i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= s; j++) 
            memo[i][j] = -1;

    printf ("%d\n", dp (0, s));
}
