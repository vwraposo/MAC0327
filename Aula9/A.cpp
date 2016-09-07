#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100000;
vector<int> adj[MAX+5];
int cats[MAX+5], visited[MAX+5];
int n, m, ans = 0;

void dfs (int v, int c) {
    if (visited[v]) return;
    visited[v] = 1;

    if (cats[v] == 0) c = 0;
    else c++;
    if (c > m) return;
    if (adj[v].size () == 1 && v != 1 && c <= m) {
        ans++;
        return;
    }
    for (int i : adj[v]) {
        dfs (i, c); 
    }
}

int main () {
    ios::sync_with_stdio (false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int cat;
        cin >> cat;
        cats[i] = cat;
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].pb (y);
        adj[y].pb (x);
    }
    dfs (1, 0);
    cout << ans << endl;
    
    return 0;
}

