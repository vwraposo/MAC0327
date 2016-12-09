#include <bits/stdc++.h>
#define mem(x,val) memset((x), (val), sizeof (x));
#define ff first
#define ss second 
#define pb push_back
#define clr clear()
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int out[MAX][3];
map<int, int> mp;
set<pii> balls;
int n;

int main () {
    int ans = 0;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        mp[x]++;
    }

    for (auto it : mp)
            balls.insert (make_pair (-it.ss, it.ff));


    while (balls.size () >= 3) {
        set<pii>::iterator it = balls.begin ();
        pii a = *it++;
        pii b = *it++;
        pii c = *it;
        int freq = max (a.ff, max (b.ff, c.ff));

        if (c.ss < b.ss) swap (b, c);
        if (b.ss < a.ss) swap (a, b);
        if (c.ss < b.ss) swap (b, c);

        //cout << a.ss<< ":" << a.ff << "  " << b.ss << ":" << b.ff << "  " << c.ss << ":" << c.ff << "  " << freq << endl;

        for (int i = 0; i < -freq; i++) {
            out[ans][0] = c.ss;
            out[ans][1] = b.ss;
            out[ans++][2] = a.ss;
        }


        balls.erase (a);
        balls.erase (b);
        balls.erase (c);

        if (a.ff - freq != 0) {
            a.ff -= freq;
            balls.insert (a);
        }
        if (b.ff - freq != 0) {
            b.ff -= freq;
            balls.insert (b);
        }
        if (c.ff - freq != 0) {
            c.ff -= freq;
            balls.insert (c);
        }
    }


    printf ("%d\n", ans);
    for (int i = 0; i < ans; i++) {
        printf ("%d %d %d\n", out[i][0], out[i][1], out[i][2]);
    }

    return 0;
}
