#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

typedef struct {
    int l;
    int r;
    int c;
} point;

const int MAX = 30;
int d[MAX+5][MAX+4][MAX+5];
int visited[MAX+5][MAX+4][MAX+5];
int L, R, C;
point S, E;

int valid (int x, int y, int z) {
        if (x < 0 || x >=L || y < 0 || y >= R || z < 0 || z >= C || d[x][y][z] == 0 || visited[x][y][z] != -1) return 0;
        return 1;
}

void bfs () {
    queue<point> q;
    q.push (S);
    visited[S.l][S.r][S.c] = 0;

    while (!q.empty ()) {
        point x = q.front ();
        q.pop ();
        if (x.l == E.l && x.r == E.r && x.c == E.c)  return;
        point np;
        // Upon
        np.l = x.l + 1; np.r = x.r; np.c = x.c;
        if (valid (np.l, np.r, np.c)) {
            q.push (np);
            visited[np.l][np.r][np.c] = visited[x.l][x.r][x.c] + 1;
        }
        // Down
        np.l = x.l - 1; np.r = x.r; np.c = x.c;
        if (valid (np.l, np.r, np.c)) {
            q.push (np);
            visited[np.l][np.r][np.c] = visited[x.l][x.r][x.c] + 1;
        }
        // North
        np.l = x.l; np.r = x.r + 1; np.c = x.c;
        if (valid (np.l, np.r, np.c)) {
            q.push (np);
            visited[np.l][np.r][np.c] = visited[x.l][x.r][x.c] + 1;
        }
        // South
        np.l = x.l; np.r = x.r-1; np.c = x.c;
        if (valid (np.l, np.r, np.c)) {
            q.push (np);
            visited[np.l][np.r][np.c] = visited[x.l][x.r][x.c] + 1;
        }
        // East
        np.l = x.l; np.r = x.r; np.c = x.c + 1;
        if (valid (np.l, np.r, np.c)) {
            q.push (np);
            visited[np.l][np.r][np.c] = visited[x.l][x.r][x.c] + 1;
        }
        // West
        np.l = x.l; np.r = x.r; np.c = x.c-1;
        if (valid (np.l, np.r, np.c)) {
            q.push (np);
            visited[np.l][np.r][np.c] = visited[x.l][x.r][x.c] + 1;
        }
    }
}

int main () {
    ios::sync_with_stdio (false);
    cin >> L >> R >> C;
    while (L && R && C) {
        for (int l = 0; l < L; l++) 
            for (int r = 0; r < R; r++)    
                for (int c = 0; c < C; c++) {
                    char ch;
                    cin >> ch;
                    if (ch == '.') 
                        d[l][r][c] = 1;
                    else if (ch == '#') 
                        d[l][r][c] = 0;
                    else if (ch == 'S') {
                        d[l][r][c] = 1;
                        S.l = l;
                        S.r = r;
                        S.c = c;
                    }
                    else if (ch == 'E') {
                        d[l][r][c] = 1;
                        E.l = l;
                        E.r = r;
                        E.c = c;
                    }
                }
        memset (visited, -1, sizeof(visited));
        bfs ();
        if (visited[E.l][E.r][E.c] == -1)
            cout << "Trapped!" << endl;
        else 
            cout << "Escaped in " << visited[E.l][E.r][E.c] << " minute(s)." << endl;
        cin >> L >> R >> C;
    }
}

