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

const int MAX = 50000;

struct no {
    int sum;
    int prefixSum;
    int sufixSum;
    int ans;
    
} tree[4*MAX];

struct no operator+ (struct no a, struct no b) {
    struct no res;
    res.sum = a.sum + b.sum;
    res.prefixSum = max (a.prefixSum, a.sum + b.prefixSum);
    res.sufixSum = max (b.sufixSum, b.sum + a.sufixSum);
    res.ans = max (a.sufixSum + b.prefixSum, max (a.ans, b.ans));
    return res;
}
    
int A[MAX];
int n, m;

void build (int node = 1, int start = 0, int end = n-1) {
    if (start == end) {
        tree[node].sum = A[start];
        tree[node].prefixSum = A[start];
        tree[node].sufixSum = A[start];
        tree[node].ans = A[start];
        return;
    }
    int m = (start + end) / 2;
    build (2*node, start, m);
    build (2*node + 1, m+1, end);
    tree[node] = tree[2*node] + tree[2*node+1];
}

void update (int idx, int val, int node = 1, int start = 0, int end = n-1) {
    if (idx < start || idx > end) return;
    if (start == end) {
        tree[node].sum = val;
        tree[node].prefixSum = val;
        tree[node].sufixSum = val;
        tree[node].ans = val;
        return;
    }
    int m = (start + end) / 2;
    update (idx, val, 2*node, start, m);
    update (idx, val, 2*node+1, m+1, end);
    tree[node] = tree[2*node] + tree[2*node+1];
}

struct no query (int l, int r, int node = 1, int start = 0, int end = n-1) {
    if (start >= l && end <= r) 
        return tree[node];
    if (l > end || r < start) {
        struct no e;
        e.sum = 0;
        e.prefixSum = -MAX;
        e.sufixSum = -MAX;
        e.ans = -MAX;
        return e;
    } 
    int m = (start + end) / 2;
    return query (l, r, 2*node, start, m) + query (l, r, 2*node+1, m+1, end);
}


int main () {
    ios::sync_with_stdio (false);
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> A[i];
    build ();

    cin >> m;
    for (int i = 0; i < m; i++) {
        int op, x, y;
        cin >> op >> x >> y;
        x--; 
        if (op) {
            y--;
            cout << query (x, y).ans << endl;
        }
        else 
            update (x, y);
        //for (int j = 1; j < 2*n; j++) {
            //cout << tree[j].ans << " ";
        //}
        //cout << endl;
    }

    return 0;
}
