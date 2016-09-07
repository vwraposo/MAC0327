#include <bits/stdc++.h>
#define mem(x,val) memset ((x), (val), sizeof (x))
#define xx first
#define yy second 
#define pb push_back
#define mp make_pair
#define clr clear()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1000000;

vector<int> adj[MAX+5];
int visited[MAX+5];
int f, s, g, u, d;

void bfs () {
    queue<int> q;
    q.push (s);
    visited[s] = 0;
    while (!q.empty ()) {
        int v = q.front ();
        q.pop ();
        if (v == g) return;
        for (int i : adj[v])
            if (visited[i] == -1) {
                q.push (i);
                visited[i] = visited[v] + 1;
            }
    }
}

int main () {
    ios::sync_with_stdio (false);
    cin >> f >> s >> g >> u >> d;
    FOR(i, 1, f+1) {
        if (i+u <= f)
            adj[i].pb (i+u);
        if (i-d > 0)
            adj[i].pb (i-d);
    }
    mem(visited, -1);
    bfs ();

    if (visited[g] == -1) 
        cout << "use the stairs" << endl;
    else 
        cout << visited[g] << endl;

    return 0;
}
