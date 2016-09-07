#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int v[35];
int s, t;

int gdc (int a, int b) {
    if (b == 0) return a;
    return gdc (b, a%b);
}

int can (int x, int p) {
    for (int i = 0; i < p; i++)
        if (gdc (v[i], x) != 1) return 0;
    return 1;
}

void solve (int n, int p, int ini) {
    if (n == 0 && p == t) {
        for (int i = 0; i < t-1; i++) 
            cout << v[i] << " ";
        cout << v[t-1] << endl;

        return;
    }
    if (n < 0 || p > t) return;
    //debug("n: %d, p: %d, ini: %d\n", n, p, ini);
    for (int i = ini; i <= n; i++)
        if (can (i, p)) { 
            v[p] = i;
            solve (n-i, p+1, i);
        }
}

int main () {
    ios::sync_with_stdio (false);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> s >> t;
        cout << "Case " << i << ":" << endl;

        solve (s, 0, 1);
    }
}
