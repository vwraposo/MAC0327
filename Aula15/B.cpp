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

const int MAX = 1050;

struct ed {
    int to, f, c;
} edges[40*MAX];

vector<int> adj[MAX], p[25];
int cur;
int seen[MAX], tempo;

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
        if (seen[e.to] < tempo && e.c - e.f > 0) { 
            if (int a = dfs (e.to, t, min (mn, e.c-e.f))) {
                edges[adj[s][i]].f += a;
                edges[adj[s][i]^1].f -= a;
                return a;
            }
        }
    }
    return 0;
}

int main () {
    ios::sync_with_stdio (false);
    int nk, np, s = 0, t, sum = 0;
    cin >> nk >> np;
    while (nk && np) { 
        cur = 0;
        sum = 0;
        t = nk+np+1;
        for (int i = 1; i <= nk; i++) {
            int x;
            cin >> x;
            add_ed (i, t, x, 0);
            sum += x;
        }


        for (int i = nk+1; i <= np+nk; i++) {
            add_ed (s, i, 1, 0);
            int c;
            cin >> c;
            for (int j = 0; j < c; j++) {
                int x;
                cin >> x;
                add_ed (i, x, 1, 0);
            }
        }

        tempo = 1;
        int flow = 0;
        while (int a = dfs (s, t, INT_MAX)) {
            flow += a;
            tempo++;
        }

        if (flow == sum) {
            cout << 1 << endl;
            for (int i = nk+1; i < t; i++) { 
                for (int a : adj[i]) {
                    if (edges[a].to > 0 && edges[a].to <= nk && edges[a].f == 1) {
                        p[edges [a].to].pb (i-nk);
                    }
                }
            }
            for (int i = 1; i <= nk; i++) {
                for (int j = 0; j < p[i].size ()-1; j++) 
                    cout << p[i][j] << " ";
                cout << p[i][p[i].size ()-1] << endl;
            }
        }
        else {
            cout << 0 << endl;
        }


        for (int i = 0; i <= t; i++) {
            if (i <= nk) p[i].clr;
            adj[i].clr; seen[i] = 0;
        }

        cin >> nk >> np;
    }

    return 0;
}

