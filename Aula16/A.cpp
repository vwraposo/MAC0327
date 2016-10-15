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

const int MAX = 701;

struct ed{
    int to;
    int f;
    int c;
} edges[2*MAX];

int cur = 0;
vector<int> adj[MAX];
int seen[53];
int tempo = 0;

int mp (char c) {
    if (isupper (c))
        return c - 'A';
    else
        return c - 'a' + 26;

}

void add_ed (int a, int b, int cp, int rc) {
    edges[cur].to = b; edges[cur].f = 0; edges[cur].c = cp;
    adj[a].pb (cur++);
    edges[cur].to = a; edges[cur].f = 0; edges[cur].c = rc;
    adj[b].pb (cur++);
}

int dp (int s, int t, int f) {
    if (s == t) return f;
    seen[s] = tempo;

    for (int i = 0; i < adj[s].size (); i++) {
        ed e = edges[adj[s][i]];
        if (seen[e.to] < tempo && e.c - e.f > 0) {
            if (int a = dp (e.to, t, min (f, e.c - e.f))) {
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
    int n; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b;
        int c;
        cin >> a >> b >> c;
        add_ed (mp (a), mp (b), c, 0);
    }

    tempo++;
    int flow = 0;
    while (int a = dp (0, 25, INT_MAX)) { 
        flow += a;
        tempo++;
    }

    cout << flow << endl;

    return 0;
}
