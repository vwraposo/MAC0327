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

const int MAX = 100000;

pii points[MAX];
int n;

int cross (pii p, pii r) {
    return r.ff*p.ss - r.ss*p.ff;
}
int main () {
    ios::sync_with_stdio (false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> points[i].ff >> points[i].ss;

    pii r1, r2, r3;
    pii a, b;
    if (points[0].ff < points[1].ff) {
        a = points[1]; b = points[0];
    }
    else if (points[0].ff == points[1].ff && points[0].ss < points[1].ss) {
        a = points[1]; b = points[0];
    }
    else {
        a = points[0]; b = points[1];
    }
    r1 = mp (a.ff - b.ff, a.ss - b.ss);

    for (int i = 2; i < n; i++) {
        pii c = points[i];    
        int in = 0;
        int cr0 = cross (c, r1);
        if (cr0 == 0) continue;
        r2 = mp (c.ff - b.ff, c.ss - b.ss);
        r3 = mp (a.ff - c.ff, a.ss - c.ss);
        for (int j = 2; j < n; j++) {
            if (j == i) continue; 
            // Verifica se ta no triangulo
            int cr1 = cross (points[j], r1);
            int cr2 = cross (points[j], r2);
            int cr3 = cross (points[j], r3);
            if ((cr1 <= 0 != cr0 <= 0) && (cr2 <= 0 != cr0 <= 0) && (cr0 <= 0 != cr3 <= 0)) in++;
        }
        if (in == 0) {
            cout << "1 2 " << i+1 << endl;
            break;
        }
    }

    return 0;
}
