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

const int MAX = 1000005;
int paired[MAX];

int main () {
    ios::sync_with_stdio (false);
    string s;
    getline (cin, s);
    int l = s.size ();
    int np = 0;
    int j = 0;
    for (int i = 0; i < l; i++) {
        if (paired[i]) continue;
        if (!paired[i] && s[i] == ')') {np++; j++; continue;}
        for (j = max (i+1, j); j < l; j++) {
            if (!paired[j] && s[j] == ')') {
                paired[i] = paired[j] = 1;
                break;
            }
        }
        if (!paired[i]) np++;
    }

    cout << l - np << endl;

    return 0;
}

