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

const int MAX = 50005;

int memo[MAX][105];
int V[MAX];
int m, n;

int dp (int t, int coin) {
    if (t == m) return 0;
    if (coin == n) return MAX;

    if (memo[t][coin] != -1) return memo[t][coin];

    int a;
    if (V[coin] + t <= m) 
        a = min (1+dp(t+V[coin], coin), dp(t, coin+1));
    else 
        a = dp (t, coin+1);

    return memo[t][coin] = a;
}

int main () {
    ios::sync_with_stdio (false);
    cin >> m;
    while (m) {
        cin >> n;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++)
                memo[i][j] = -1;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            V[i] = x;
        }

        int ans = dp (0, 0);
        if (ans < MAX) {
            cout << ans << endl;
        }
        else 
            cout << "Impossivel" << endl;


        cin >> m;
    }
    
    return 0;    
}

