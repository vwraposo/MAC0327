#include <bits/stdc++.h>

using namespace std; 

const int MAX = 205;

int memo[MAX][MAX][MAX];
int V[MAX];
int n;

int dp (int num, int w, int b) {
    if (num == n+1) return 0;

    if (memo[num][w][b] != -1) return memo[num][w][b];

    int a1, a2;
    a1 = a2 = INT_MAX;
    if (V[num] < V[w])
        a1 = dp (num+1, num, b); 
    if (V[num] > V[b])
        a2 = dp (num+1, w, num);

    memo[num][w][b] = min (a1, a2); 


    memo[num][w][b] = min (memo[num][w][b], 1 + dp (num+1, w, b));  


    return memo[num][w][b];
}

int main () {
    while (scanf ("%d", &n) && n != -1) {
        for (int i = 0; i <= n+1; i++)
            for (int j = 0; j <= n+1; j++)
                for (int k = 0; k <= n+1; k++)
                    memo[i][j][k] = -1; 

        V[0] = INT_MIN;
        V[n+1] = INT_MAX;
        for (int i = 1; i <= n; i++)
            scanf("%d", &V[i]);

        printf ("%d\n", dp (1, n+1, 0));
    }

    return 0;
}

