#include <bits/stdc++.h>
#define pb push_back

using namespace std;

vector<int> adj[100];
int visited[100];
int N;

int dfs (int v, int c) {
    if (visited[v] != -1)
        if (visited[v] != c) {
            return 0;
        }
        else return 1;
    visited[v] = c;
    c = (c + 1) % 2;
    for (int a : adj[v]) {
        if (!dfs (a, c))
            return 0;
    }

    return 1;
}

int main () {
    scanf ("%d", &N);
    for (int i = 1; i <= N; i++) {
        int x;
        scanf ("%d", &x);
        while (x != 0) {
            adj[i].pb (x);
            adj[x].pb (i);
            scanf ("%d", &x);
        }
    }

    memset (visited, -1, (N+1)*sizeof (int));  
    if (!dfs (1, 0))
        printf ("-1\n");
    else {
        for (int i = 1; i <= N; i++)
            printf ("%d", visited[i]);
        printf ("\n");
    }
    return 0;
}

