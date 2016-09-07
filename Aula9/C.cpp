#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> adj[10005];
int visited[10005];
int circuit = 0;

void dfs (int u, int v) {
    if (visited[v]) { circuit = 1; return;}
    visited[v] = 1;
    for (int i : adj[v])
        if (i != u) dfs (v, i);
}

int main () {
    ios::sync_with_stdio (false);
    int N, M;
    cin >> N >> M;
    if (M != N-1) { 
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].pb (y);
        adj[y].pb (x);
    }
    dfs (0, 1);
    if (circuit) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}

