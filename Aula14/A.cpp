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


char a[4], b[4] ;
char as[4], bs[4];

int main () {
    ios::sync_with_stdio (false);
    char x, y, z, w;
    cin >> x >> y >> z >> w;
    a[0] = x; a[1] = y; a[2] = w; a[3] = z; 
    cin >> x >> y >> z >> w;
    b[0] = x; b[1] = y; b[2] = w; b[3] = z; 

    int start = 0;
    int it = 0;
    for (int k = 0; k < 2; k++)
        for (int i = 0; i < 4; i++) {
            if (it == 3) break;
            if (start) {
                if (a[i] != 'X')
                    as[it++] = a[i];
            }
            else {
                if (a[i] == 'A') { start = 1; as[it++] = a[i]; }
            }
        }

    start = 0;
    it = 0;
    for (int k = 0; k < 2; k++)
        for (int i = 0; i < 4; i++) {
            if (it == 3) break;
            if (start) {
                if (b[i] != 'X')
                    bs[it++] = b[i];
            }
            else {
                if (b[i] == 'A') { start = 1; bs[it++] = b[i]; }
            }
        }
           
   if (strcmp (as, bs) == 0) cout << "YES" << endl; 
   else cout << "NO" << endl;

    return 0;
}

