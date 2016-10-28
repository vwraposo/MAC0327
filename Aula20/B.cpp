#include <bits/stdc++.h>
#define mem(x,val) memset((x), (val), sizeof (x));
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define clr clear()
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int tree[4*MAX];
int n, k;

void update (int node, int start, int end, int idx, int val) {
    if (start > idx || end < idx) return;
    if (start == end) {
        tree[node] = val;
        return;
    }
    int m = (start + end) / 2;
    update (2*node, start, m, idx, val);
    update (2*node+1, m+1, end, idx, val);
    tree[node] = tree[2*node] * tree[2*node+1];
}

int query (int node, int start, int end, int l, int r) {
    if (start > r || end < l) return 1;
    if (l <= start && r >= end) return tree[node];
    int m = (start + end) / 2;
    return query (2*node, start, m, l, r) * query (2*node+1, m+1, end, l, r);
}

int main () {
    ios::sync_with_stdio (false);
    char c;
    while (scanf ("%d %d", &n, &k) != EOF) {
        memset (tree, 0, sizeof (tree));
        for (int i = 0; i < n; i++) {
            int x;
            scanf ("%d", &x);
            if (x > 0) x = 1;
            else if (x < 0) x = -1;
            update (1, 0, n-1, i, x);
        }
        //for (int i = 1; i < 2*n; i++) 
            //cout << tree[i] << " ";
        //cout << endl;
        for (int i = 0; i < k; i++) {
            scanf (" %c", &c);
            if (c == 'C') {
                int x, val;
                scanf ("%d %d", &x, &val);
                if (val > 0) val = 1;
                else if (val < 0) val = -1;
                update (1, 0, n-1, x-1, val);
            }
            else {
                int l, r;
                scanf ("%d %d", &l, &r);
                l--; r--;
                int ans = query (1, 0, n-1, l, r);
                if (ans == 1)
                    printf ("+");
                else if (ans == -1)
                    printf ("-");
                else
                    printf ("0");
            }
        }
        printf ("\n");
    }
    
    return 0;
}

