#include <bits/stdc++.h>
#define mem(x,val) memset((x), (val), sizeof (x));
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define clr clear()
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int memo[MAX][50];
int cubo[50];
int n;

int dp (int s, int i) {
    if (s == 0) return 0;
    if (i+1 == 50 || s < 0) return MAX;
    if (memo[s][i] != -1) 
        return memo[s][i];
    return memo[s][i] = min (dp (s, i+1), dp (s-cubo[i], i) + 1);
}

int main () {
    ios::sync_with_stdio (false);
    int t = 1;

    for (int i = 0; i < 50; i++) {
        cubo[i] = (i+1)*(i+1)*(i+1);
    }

    memset (memo, -1, sizeof (memo));

    while (scanf ("%d", &n) != EOF) {
        printf ("Case #%d: %d\n", t++, dp (n, 0));
    }

    return 0;
}

