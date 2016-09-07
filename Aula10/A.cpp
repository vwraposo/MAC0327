#include <bits/stdc++.h>
#define mem(x,val) memset((x), (val), sizeof(x));
#define xx first
#define yy second 
#define pb push_back
#define mp make_pair
#define clr clear()
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 250;

int di[] = {1, 0, -1 , 0};
int dj[] = {0, 1, 0, -1};

int d[MAX+5][MAX+5];
int size;
int N, M;
int slicks[100000];

int valid (int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M || d[r][c] != 0 || d[r][c] == -1) return 0;
    return 1;
}
void dfs (int r, int c, int colour) {
    if (!valid (r, c)) return;
    d[r][c] = colour;
    size += 1;
    for (int i = 0; i < 4; i++) 
        dfs (r+di[i], c+dj[i], colour);
}

int main () {
    ios::sync_with_stdio (false);
    cin >> N >> M;
    while (N && M) {
        mem(slicks, 0);
        FOR(i, 0, N) {
            FOR(j, 0, M) { 
                int x;
                cin >> x;
                if (x == 0) d[i][j] = -1;
                else d[i][j] = 0;
            }
        }
    
        int colour = 1;
        FOR(i, 0, N) 
            FOR(j, 0, M) 
                if (d[i][j] == 0) {
                    size = 0;
                    dfs (i, j, colour++);
                    slicks[size]++;
                }

        cout << colour-1 << endl;
        FOR(i, 1, N*M+1) {
            if (slicks[i] != 0) 
                cout << i << " " << slicks[i] << endl;
        }
        

        cin >> N >> M;
    }
    

}

