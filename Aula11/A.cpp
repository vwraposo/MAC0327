#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};
int N, M;
int d[15][15];
int visited[15][15];
int ans;


int valid (int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M || d[x][y] == 2 || d[x][y] == 3 || visited[x][y] != 0)
        return 0;
    return 1;
}

void bfs (int x, int y) {
    queue< pair<int, int> > q;

    q.push (make_pair (x, y));
    while (!q.empty ()) {
        pair<int, int> p = q.front ();
        q.pop ();
        x = p.first; y = p.second;
        if (d[x][y] == 0) {
            ans = visited[x][y];
            return;
        }
        for (int i = 0; i < 4; i++) {
            if (valid (x+di[i], y+dj[i])) {
                q.push (make_pair (x+di[i], y+dj[i]));  
                visited[x+di[i]][y+dj[i]] = visited[x][y] + 1;
            }
        }
    }

    return;
}
int main () {
    int bx, by;

    scanf ("%d %d", &N, &M);
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) {
            scanf ("%d", &d[i][j]);
            if (d[i][j] == 3) {bx = i; by = j; }
        }

    bfs (bx, by);

    printf ("%d\n", ans);

    return 0;
}

