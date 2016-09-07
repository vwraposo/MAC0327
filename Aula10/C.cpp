#include <bits/stdc++.h>
#define mem(x,val) memset((x), (val), sizeof (x));
#define xx first
#define yy second 
#define pb push_back
#define mp make_pair
#define clr clear()
#define FOR(i,a,b) for (int i = (a);i < (b); i++)
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100;
vector<int> adj[MAX+5][MAX+5];
int visited[MAX+5][MAX+5];
int n, m, c = 0, ans;

void dfs (int colour, int u, int v) {
    if (visited[colour][u]) return;
    visited[colour][u] = 1; 
    if (u == v) { ans++; return; }
    for (int i : adj[colour][u]) 
        dfs (colour, i, v);
}
int main () {
    ios::sync_with_stdio (false);
    cin >> n >> m;
    FOR(i, 0, m) {
        int x, y, z;
        cin >> x >> y >> z;
        c = max (c, z);
        adj[z][x].pb (y);
        adj[z][y].pb (x);
    }
    int q;
    cin >> q;
    FOR(i, 0, q) {
        int u, v;
        cin >> u >> v;
        ans = 0;
        FOR(j, 1, c+1) {
            dfs (j, u, v);
            mem(visited[j], 0);
        }
        cout << ans << endl;
    }

    return 0;
}

