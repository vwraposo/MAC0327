#include <stdio.h>
#include <string.h>

#define MAX  105

int memo[MAX][MAX];
int m[MAX][MAX];
int w, h;

int max (int a, int b) {return a > b ? a : b;}

int dp (int i, int j) {
    int b, bd, be;

    if (i >= h || j < 0 || j >= w) return 0;

    if (memo[i][j] != -1) return memo[i][j];

    b =  dp (i+1, j);
    bd = dp (i+1, j+1);
    be = dp (i+1, j-1);

    return memo[i][j] = m[i][j] + max (b, max (bd, be));


}

int main () {
    int T;
    int i, j;
    int ans = 0;
    scanf ("%d", &T);
    while (T--) {
        ans = 0;
        memset (memo, -1, sizeof (memo));

        scanf ("%d %d", &h, &w);
        for (i = 0; i < h; i++)
            for (j = 0; j < w; j++)
                scanf ("%d", &m[i][j]);

        for (i = 0; i < w; i++)
            ans = max (ans, dp (0, i));

        printf ("%d\n", ans); 
    }

    return 0;
}

