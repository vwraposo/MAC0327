#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) //fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 9;

int ans[MAX+2][MAX+2];
int rows[MAX+2][MAX+2];
int columns[MAX+2][MAX+2];
int boxes[MAX+2][MAX+2];
int N, sq, solved;

int getBox (int r, int c) {
    return r/N*N + c/N;
}

void sudoku (int r, int c) {
    if (solved) return;
    if (r == sq && c == 0) {
        for (int i = 0; i < sq; i++) {
            for (int j = 0; j < sq-1; j++)
                cout << ans[i][j] << " ";
            cout << ans[i][sq-1] << endl;
        }

        solved = 1;
    }
    else {
        if (ans[r][c]) 
            sudoku (c == sq-1 ? r+1 : r, c == sq-1 ? 0 : c+1);
        else {
            for (int i = 1; i <= sq; i++) {
                    debug("Check r: %d, c: %d b : %d, i: %d\n", rows[r][i], columns[c][i], boxes[getBox (r, c)][i], i);
                if (!rows[r][i] && !columns[c][i] && !boxes[getBox (r, c)][i]) {
                    debug("row: %d, column: %d, ans: %d, i: %d\n", r, c, ans[r][c], i);
                    rows[r][i] = columns[c][i] = boxes[getBox (r, c)][i] = 1;
                    ans[r][c] = i;

                    sudoku (c == sq-1 ? r+1 : r, c == sq-1 ? 0 : c+1);

                    if (solved) return;

                    rows[r][i] = columns[c][i] = boxes[getBox (r, c)][i] = 0;

                }
            }
            ans[r][c] = 0;
        }
    }
}

int main () {
    ios::sync_with_stdio (false);
    int space = 0;
    while (cin >> N) {
        sq = N * N;
        
        for (int i = 0; i < sq; i++) 
            for (int j = 0; j < sq; j++) {
                int x;
                cin >> x; 
                ans[i][j] = x;
            }

        // Zerando os vetores
        for (int i = 0; i < sq; i++) 
            for (int j = 1; j <= sq; j++)
                rows[i][j] = columns[i][j] = boxes[i][j] = 0;


        for (int i = 0; i < sq; i++) 
            for (int j = 0; j < sq; j++) {
                if (ans[i][j]) {
                    int x = ans[i][j];
                    //debug("row: %d, column: %d, ans: %d\n", i, j, x);
                    rows[i][x] = columns[j][x] = boxes[getBox (i, j)][x] = 1;
                }
            }

        if (space) cout << endl;
        space = 1;

        solved = 0;
        sudoku (0, 0);

        if (!solved) 
            cout << "NO SOLUTION" << endl;
    }

    return 0;
}

