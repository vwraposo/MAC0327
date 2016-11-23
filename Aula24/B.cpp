#include <bits/stdc++.h>
#define N 1
#define S 2
#define E 3
#define W 4

using namespace std;

int main () {
    int n;
    scanf ("%d", &n);
    int ax, ay, nx, ny;
    int aw = 0, nw = 0;
    int ans= 0;
    scanf ("%d %d", &ax, &ay);
    for (int i = 0; i < n; i++) {
        scanf ("%d %d", &nx, &ny);
        //cout << "(" << ax << "" << ay << ")" << "->" << "(" << nx << "" << ny << ")" << endl;
        if (nx == ax)
            if (ny > ay) nw = N;
            else nw = S;
        else 
            if (nx > ax) nw = E;
            else nw = W;

        if (aw) {
            if (aw == N && nw == W) ans++; 
            if (aw == W && nw == S) ans++; 
            if (aw == E && nw == N) ans++; 
            if (aw == S && nw == E) ans++; 
        }
        //cout << aw << "->" << nw << endl;
        aw = nw;
        ax = nx;
        ay = ny;
    }
    printf ("%d\n", ans);

    return 0;
}
