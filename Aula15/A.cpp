#include <bits/stdc++.h>
#define pb push_back 

using namespace std;

const int MAX = 1000000;
struct ed {
    int to, c, f;
} edges[MAX];

vector<int> adj[105];
int cur = 0;
int seen[105], tempo;

void add_ed (int a, int b, int cp, int rc) {
    edges[cur].to = b; edges[cur].f = 0; edges[cur].c = cp;
    adj[a].pb (cur++);
    edges[cur].to = a; edges[cur].f = 0; edges[cur].c = rc;
    adj[b].pb (cur++);
}

int dfs (int s, int t, int mn) {
    seen[s] = tempo;
    if (s == t) {
        return mn;
    }
    for (int i : adj[s]) {
        ed e = edges[i];
        if (seen[e.to] < tempo && e.c - e.f > 0){ 
            if (int a = dfs (e.to, t, min (mn, e.c-e.f))) {
                edges[i].f += a;
                edges[i^1].f -= a;
                return a;
            }
        }
    }
    return 0;
} 

int main () {
    int net = 1;
    int s, t, m, n;
    scanf ("%d", &n);
    while (n) {

        cur = 0;
        scanf ("%d %d %d", &s, &t, &m);
        for (int i = 0; i < m; i++) {
            int a, b, cp;
            scanf ("%d %d %d", &a, &b, &cp);
            add_ed (a, b, cp, cp);
        }

        int flow = 0;
        tempo = 1;
        while (int a = dfs (s, t, INT_MAX)) {
            flow += a;
            tempo++;
        }   
        printf ("Network %d\nThe bandwidth is %d.\n\n", net++, flow);

        for (int i = 1; i <= n; i++) {adj[i].clear (); seen[i] = 0;}
        scanf ("%d", &n);
    }

    return 0;
}

