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
typedef pair<ll, ll> pll;

const int MAX = 10000;

pii points[MAX];
int n;

ll cross (pll p, pll r) {
    return r.ff*p.ss - r.ss*p.ff;
}

int main () {
    ios::sync_with_stdio (false);
    cin >> n; 
    for (int i = 0; i < n; i++) 
        cin >> points[i].ff >> points[i].ss;

    for (int i = 1; i < n; i++) {
        int es, dir;
        es = dir = 0;
        pii r = mp (points[i].ff - points[0].ff, points[i].ss - points[0].ss);
        for (int j = 1; j < n; j++) {
            if (j == i) continue;
            pii p = mp (points[j].ff - points[0].ff, points[j].ss - points[0].ss);
            if (cross (p, r) > 0) es++;
            else dir++;
        }
        if (es == dir) {
            cout << "1 " << i+1 << endl;
            break;
        }
    }

    return 0;
}

