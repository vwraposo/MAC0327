#include <bits/stdc++.h>
#define mem(x,val) memset((x), (val), sizeof (x));
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define clr clear()
#define FOR(i,a,b) for (int i = (a);i < (b); i++)
#define debug(args...) //fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 500;
const ll Inf = 1000;

ll d[MAX+5][MAX+5];
int v[MAX+5];
int used[MAX+5];
ll ans[MAX+5];

int main () {
    ios::sync_with_stdio (false);
    int n;
    cin >> n;
    FOR(i, 1, n+1)
        FOR(j, 1, n+1) {
            ll x;
            cin >> x;
            if (x == 0 && i != j)
                d[i][j] = Inf;
            else
                d[i][j] = x;
        }
    for (int i = n; i > 0; i--) {
        int x;
        cin >> x;
        v[i] = x;
    }

    FOR(t, 1, n+1) {
        debug("Insere %d\n", v[t]);
        int k = v[t];
        used[k] = 1;
        
        FOR(i, 1, n+1)
            FOR(j, 1, n+1) {
                d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
                if (used[i] && used[j]) 
                    ans[t] += d[i][j];
            }
    }

    for (int i = n; i > 1; i--) 
        cout << ans[i] << " ";
    cout << ans[1] << endl;

    return 0;
}

