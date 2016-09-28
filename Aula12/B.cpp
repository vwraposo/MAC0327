#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int MAX = 2005;
int a[MAX], b[MAX], w[MAX];
int d[MAX][MAX];
int n, m, possible;
int Inf = INT_MAX;

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        possible = 0;
        scanf ("%d %d", &n, &m);
        for (int i = 0; i < m; i++)
            scanf ("%d %d %d", &a[i], &b[i], &w[i]);

        d[0][0] = 0;
        for (int i = 1; i < n; i++)
            d[i][0] = Inf;

        // Bellman-Ford
        for (int k = 1; k < n; k++) {
            for (int i = 0; i < n; i++) d[i][k] = d[i][k-1];
            for (int i = 0; i < m; i++)
                if (d[a[i]][k-1] < Inf) 
                    d[b[i]][k] = min (d[b[i]][k], d[a[i]][k-1] + w[i]);
        }
        for (int i = 0; i < m; i++)
            if (d[a[i]][n-1] < Inf && d[b[i]][n-1] > d[a[i]][n-1] + w[i])
                possible = 1;

        if (possible)
            printf ("possible\n");
        else 
            printf ("not possible\n");

    }
    return 0;
}

