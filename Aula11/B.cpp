#include <bits/stdc++.h>
#define mem(x,val) memset((x), (val), sizeof (x));
#define xx first
#define yy second 
#define pb push_back
#define mp make_pair
#define clr clear()
#define FOR(i,a,b) for (int i = (a);i < (b); i++)
#define debug(args...) //fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> adj[10005];
vector<int> w;
int visited[10005][10005];

// v indo para s
int dfs (int v, int u, int s) {
    debug("%d -> %d, indo para %d\n", u, v, s); 
    if (u != -1 && v == s) {
                debug("Coloquei pq ciclo %d\n", v);
                w.pb (v);
                return true;
    }
    for (int a : adj[v]) {
        if (!visited[v][a]) {
            visited[v][a] = 1;
            if (dfs (a, v, s)) {
                dfs (v, -1, v);
                debug("Coloquei %d\n", v);
                if (w.back () != v) w.pb (v);
                return true;
            }
        }
    }

    return 0;
}

int main () {
    ios::sync_with_stdio (false);
    int n, m;
    cin >> n;
    FOR(i, 0, n) {
        int x, y;
        cin >> m;
        cin >> x;
        FOR(j, 0, m) {
            cin >> y;
            adj[x].pb (y);
            x = y;
        }
    }

    dfs (1, -1, 1);

    reverse (w.begin (), w.end ());
    cout << w.size () - 1 << " " ;
    FOR(i, 0, w.size ()) 
        cout << w[i] << " ";
    cout << endl; 

    return 0;
}

