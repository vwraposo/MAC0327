#include <bits/stdc++.h>
#define pb push_back

using namespace std;
const int MAX = 100000;

int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};

int a[MAX], b[MAX], we[MAX];
int d[MAX];
int mat[35][35];
int n, m;
int Inf = INT_MAX;

int main () {
    int w, h;
    scanf ("%d %d", &w, &h);
    while (w && h) {
        n = 1;  
        m = 0;
        for (int i = 0; i < w; i++)
            for (int j = 0; j < h; j++) 
                mat[i][j] = n++;

        int g;
        scanf ("%d", &g);
        for (int i = 0; i < g; i++) {
            int x, y;
            scanf ("%d %d", &x, &y);
            mat[x][y] = -Inf;
        }

        // Adding holes
        int e;
        cin >> e;
        for (int i = 0; i < e; i++) {
            int x1, y1, x2, y2, t;
            cin >> x1 >> y1 >> x2 >> y2 >> t;
            a[m] = abs (mat[x1][y1]);
            b[m] = abs (mat[x2][y2]);
            we[m] = t;
            m++;
            mat[x1][y1] = -abs (mat[x1][y1]);
        }

        // gerar grafo
        for (int i = 0; i < w; i++)
            for (int j = 0; j < h; j++) {
                for (int k  = 0; k < 4; k++) {
                    if (mat[i][j] < 0 || mat[i][j] == n-1) continue;
                    int x = i + di[k];
                    int y = j + dj[k];
                    if (x >= 0 && x < w && y >= 0 && y < h && mat[x][y] != -Inf) {
                        a[m] = abs (mat[i][j]);
                        b[m] = abs (mat[x][y]);
                        we[m] = 1;
                        m++;
                    }
                }
            }

        int never = 0;
        // Bellman-Ford
        d[1] = 0;
        for (int i = 2; i < n; i++)
            d[i] = Inf;
        
        for (int k = 0; k < n-1; k++)
           for (int i = 0; i < m; i++)
              if (d[a[i]] < Inf)
                 d[b[i]] = min (d[b[i]], d[a[i]] + we[i]); 
        for (int i = 0; i < m; i++)
           if (d[a[i]] < Inf && d[b[i]] > d[a[i]] + we[i]) 
               never = 1;
        if (!never) {
            if (d[n-1] < Inf) printf ("%d\n", d[n-1]);
            else printf ("Impossible\n");
        }
        else printf ("Never\n");


        scanf ("%d %d", &w, &h);
    }
}

