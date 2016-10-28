#include <stdio.h>
#include <string.h>

#define MAX 6105

int memo[MAX][MAX];
char s[MAX];
int l;

int min (int a, int b) {
    return a < b ? a : b;
}

int dp (int i, int j) {
    if (i >= l || i == j || j < 0) return 0;

    if (memo[i][j] != -1) return memo[i][j];

    if (s[i] == s[j]) return memo[i][j] = dp (i+1, j-1);
    return memo[i][j] = min (dp (i+1,j), dp (i, j-1)) + 1;
}

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        memset (memo, -1, sizeof (memo));

        scanf ("%s", &s);
        l = strlen (s);
        printf ("%d\n", dp (0, l-1));
    }

    return 0;
}

