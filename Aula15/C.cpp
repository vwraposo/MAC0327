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

const int MAX = 200;

struct ed {
    int to;
    int f;
    int c;
}edges[4*MAX];

vector<int> adj[105];
int cur = 0;
int n, m;
int seen[205], tempo;
int ans[205][205];

void add_ed (int a, int b, int cp, int rc) {
    edges[cur].to = b; edges[cur].f = 0; edges[cur].c = cp;
    adj[a].pb (cur++);
    edges[cur].to = a; edges[cur].f = 0; edges[cur].c = rc;
    adj[b].pb (cur++);
}

int dfs (int s, int t, int mn) {
    seen[s] = tempo;
    if (s == t) return mn;
    
    for (int i = 0; i < adj[s].size (); i++) {
        ed e = edges[adj[s][i]];
        cout << s << "->" << e.to << endl;
        if (seen[e.to] < tempo && e.c - e.f > 0) {
            if (int a = dfs (e.to, t, min (mn, e.c - e.f))) {
                edges[adj[s][i]].f += a; 
                edges[adj[s][i]^1].f -= a; 
                return a;
            }
            return 0;
        }
    }
    return 0;
}

int main () {
    ios::sync_with_stdio (false);
    int sum = 0;
    int in;
    int s, t;
    cin >> n >> m;
    s = 0; t = 2*n+1;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        add_ed (s, i, a, 0);
    }
    for (int i = 1; i <= n; i++) {
        int b;
        cin >> b;
        add_ed (i+n, t, b, 0);
        sum += b;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        add_ed (x, y+n, edges[adj[x][0]^1].c, 0);
        add_ed (y, x+n, edges[adj[y][0]^1].c, 0);
    }
    for (int i = 1; i <= n; i++) {
        add_ed (i, i+n, edges[adj[i][0]^1].c, 0);
    }

    for (int i = 0; i < 2*n+1; i++) {
        cout << "Vertice " <<  i << endl;
        for (int j = 0; j < adj[i].size (); j++)
            cout << i << "->" << edges[adj[i][j]].to << " c: " <<  edges[adj[i][j]].c << endl; 

    }
    int flow = 0;
    tempo++;
    while (int a = dfs (s, t, INT_MAX)) {
        flow += a;
        tempo++;
    }

    cout << tempo << endl;
    cout << flow << " " << sum << endl;
    if (in == sum && flow == sum) {
        cout << "YES" << endl;
        for (int v = 1; v <= n; v++) {
            int chega = edges[adj[v][0]^1].c;
            int sai = 0;
            for (int i = 0; i < adj[v].size (); i++) {
                ed e = edges[adj[v][i]];
                if (e.to > n && e.to < 2*n+1) {
                    ans[v][e.to-n] = (e.f < 0) ? 0 : e.f;
                    sai += ans[v][e.to];
                }
            }
            ans[v][v] = chega - sai;
        }

        for (int i = 1; i <= n; i++) { 
            for (int j = 1; j < n; j++) {
                cout << ans[i][j] << " ";
            }
            cout << ans[i][n] << endl;
        }
    }
    else 
        cout << "NO" << endl;

    return 0;
}

