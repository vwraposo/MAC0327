#include <bits/stdc++.h>

using namespace std;

const int MAX = 200005;
int tree[2*MAX];
int n, s;

int main () {
    int t = 1;
    while (1) {
        scanf ("%d", &n);
        if (n == 0) break;
        s = 2*n - 1; 
        memset (tree, 0, sizeof (tree));

        // Controi seg-tree
        for (int i = 1; i <= n; i++) 
            scanf ("%d", &tree[s-n+i]);
        for (int i = s-n; i > 0; i--)
            tree[i] = tree[i*2] + tree[i*2+1];

        if (t > 1) 
            printf ("\n");
        printf ("Case %d:\n", t++);
        while (1) {
            char com[5];
            scanf ("%s", com);
            if (com[0] == 'E') break;
            if (com[0] == 'M') {
                int l, r, ans = 0;
                scanf ("%d %d", &l, &r);
                l = s - n + l;
                r = s - n + r + 1;

                while (l < r) {
                    if (l % 2 == 1) {
                        ans += tree[l];
                        l = (l+1) / 2;
                    }
                    else 
                        l = l / 2;
                    if (r % 2 == 1) {
                        ans += tree[r-1];
                        r = (r-1) / 2;
                    }
                    else 
                        r = r / 2;
                }
                printf ("%d\n", ans);
            }
            else {
                int x, r;
                scanf ("%d %d", &x, &r);
                x = s - n + x;
                int diff = tree[x] - r;
                while (x > 0) {
                    tree[x] -= diff;
                    x /= 2;
                }
            }
        }
    }

}

