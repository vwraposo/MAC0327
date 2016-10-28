#include <bits/stdc++.h>

using namespace std;

const int MAX = 100005;
int tree[4*MAX];
int n, q;

void build () {
    memset (tree, 0, sizeof (tree));

    for (int i = 0; i < n; i++) 
        scanf ("%d", &tree[n+i]);

    for (int i = n-1; i > 0; i--) 
        tree[i] = min (tree[i*2], tree[i*2+1]);
}

int query (int l, int r) {
    l = n + l - 1;
    r = n + r - 1;
    int ans = INT_MAX;
    while (l < r) {
        if (l % 2 == 1) {
            ans = min (ans , tree[l]);
            l = l / 2 + 1;
        }
        else 
            l = l / 2;
        if (r % 2 == 1) 
            ans = min (ans , tree[r-1]);
        r = r / 2;
    }
    return ans;
}

int main () {
    int t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf ("%d %d", &n, &q);

        build ();
        printf ("Scenario #%d:\n", tt);
        for (int i = 0; i < q; i++) {
            int l, r;
            scanf ("%d %d", &l, &r);
            printf ("%d\n", query (l, r+1));
        }
        printf ("\n");
    }
    return 0;
}
            

