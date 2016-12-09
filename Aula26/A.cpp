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

vector <int> v;
vector <int>::iterator it;

int main () {
    ios::sync_with_stdio (false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.pb (x);
    }
    sort (v.begin (), v.end ());
    for (int i = 0; i < m; i++) {
        int q; 
        cin >> q;
        it = upper_bound (v.begin (), v.end (), q);
        cout << it - v.begin () << endl; 
    }

    return 0;
}

