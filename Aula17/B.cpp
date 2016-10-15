#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int n, a, b;
int memo[50005][2];

int dp (int t, int music) {
    if (t > n) return 0;
    if (t == n) return 1;
    if (memo[t][music] != -1) return memo[t][music];
    int resposta = 0;
    if (music == 0)
        for (int i = 1; i <= a; i++)
            resposta = (resposta % MOD + dp (t+i, 1) % MOD) % MOD;
    if (music == 1)
        for (int i = 1; i <= b; i++)
            resposta = (resposta % MOD + dp (t+i, 0) % MOD) % MOD;

    return memo[t][music] = resposta;   
}

int main () {
    scanf ("%d %d %d", &n, &a, &b);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 2; j++) 
            memo[i][j] = -1;

    int ans = (dp (0, 0) % MOD + dp (0, 1) % MOD) % MOD;
    printf ("%d\n", ans);   
}


