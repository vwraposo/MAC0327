#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 10000000;

char s[MAX];

int main () {
    ios::sync_with_stdio (false);
    int N;
    
    while (cin >> N) {
        string s, t;
        cin >> s >> t;

        string S = s + "$" + t;
        int n = S.size ();

        vector<int> Z (n, 0);

        int L = 0, R = 0;
        for (int i = 1; i < n; i++) {
            if (i > R) {
                L = R = i;
                while (R < n && S[R-L] == S[R]) R++;
                Z[i] = R - L;
                R--;
            }
            else {
                int k = i - L;
                if (Z[k] < R - i + 1) Z[i] = Z[k];
                else {
                    L = i;
                    while (R < n && S[R-L] == S[R]) R++;
                    Z[i] = R - L;
                    R--;
                }
            }
            if (Z[i] == N) 
                cout << i - N - 1 << endl;
        }
    }
    
    return 0;
}

