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

pii tree[4*MAX];
int B, P, L, N;
ll b_pot[MAX];

pii operator+ (pii a, pii b) {
    ll e = (((b_pot[b.ss] * a.ff)% P) + b.ff) % P;
    ll d = a.ss + b.ss;
    return  mp (e, d);
}

void build (int node = 1, int start = 0, int end = L - 1) { 
    if (start == end) {
        tree[node] = pii (0, 1);
        return;
    }
    int m = (start + end) / 2;
    build (2*node, start, m); 
    build (2*node+1, m+1, end); 
    tree[node] = tree[2*node] + tree[2*node+1];

}

void update (int idx, int val, int node = 1, int start = 0, int end = L-1) {
    if (idx < start || idx > end) return;
    if (start == end) {
        tree[node] = mp (val, 1);
        return;
    }
    int m = (start + end) / 2;
    update (idx, val, 2*node, start, m);
    update (idx, val, 2*node + 1, m+1, end);
    tree[node] = tree[2*node] + tree[2*node+1];
}

pii query (int l, int r, int node = 1, int start = 0, int end = L-1) {
    if (l > end || r < start) return pii (0, 0);
    if (l <= start && r >= end)
        return tree[node];
    int m = (start + end) / 2;
    return query (l, r, 2*node, start, m) + query (l, r, 2*node+1, m+1, end); 
}

int main () {
    ios::sync_with_stdio (false);
    while (scanf ("%d %d %d %d", &B, &P, &L, &N) != EOF) {
        if (!B  && !P && !L && !N) break;
        memset (tree, 0, sizeof (tree));
        ll pot = 1;
        for (int i = 0; i <= L; i++) {
            b_pot[i] = pot;
            pot = ((pot % P) * B) % P;
        }
        
        build ();
        for (int i = 0; i < N; i++) {
            char c;
            scanf (" %c", &c);
            if (c == 'E') {
                int x, val;
                scanf ("%d %d", &x, &val);
                x--;
                update (x, val%P);
            }
            else {
                int l, r;
                scanf ("%d %d", &l, &r);
                l--; r--;
                printf ("%d\n", query (l, r).ff);
            }
        }
        printf ("-\n");
    }

    return 0;
}

