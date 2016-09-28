#include <bits/stdc++.h>
#define mem(x,val) memset((x), (val), sizeof (x));
#define xx first
#define yy second 
#define pb push_back
#define mp make_pair
#define clr clear()
#define FOR(i,a,b) for (int i = (a);i < (b); i++)
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 30;

map<string, int> h;
double d[MAX+5][MAX+5];

int main () {
    ios::sync_with_stdio (false);
    int m, c = 1, n;
    cin >> n;
    while (n) {
        h.clear ();
        FOR(i, 0, n)
            FOR(j, 0, n)
                d[i][j] = 0;
                
        FOR(i, 0, n) {
            string s;
            cin >> s;
            h.insert (pair<string, int> (s, i));
        }
        int m;
        cin >> m;
        FOR(i, 0, m) {
            string s1, s2;
            double v;
            cin >> s1 >> v >> s2;
            d[h[s1]][h[s2]] = v;
        }

        //Floyd-Warshall
        FOR(k, 0, n)
            FOR(i, 0, n)
                FOR(j, 0, n)
                    d[i][j] = max (d[i][j], d[i][k]*d[k][j]);
        
        int arb = 0;
        FOR(i, 0, n)
            if (d[i][i] > 1) { 
                arb = 1; break;
            }

        cout << "Case " << c++;
        if (arb) 
            cout << ": Yes" << endl;
        else
            cout << ": No" << endl;

        cin >> n;
    }

}

