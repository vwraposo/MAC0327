#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1000000;

int main () {
    ios::sync_with_stdio (false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string s;
        int N;
        cin >> N;
        cin >> s;
        vector<int> z(N+2, 0);

        int l, r;
        l = 0, r = 0;
        z[0] = N;
        //Z algorithm
        for (int i = 1; i < N; i++) {
            if (i > r) {
                l = r = i;
                while (r < N && s[r-l] == s[r]) r++;
                z[i] = r - l; 
                r--;
            }
            else {
                int k = i - l;
                if (z[k] < r - i + 1) 
                    z[i] = z[k];
                else {
                    l = i;
                    while (r < N && s[r-l] == s[r]) r++;
                    z[i] = r-l;
                    r--;
                }
            }
        }

        cout << "Test case #" << t << endl;
        int size = 1;
        int periodo = 0;
        for (int i = 1; i < N; i++) {
            if (!periodo) {
                if (z[i] >= i) {
                    periodo = 1;
                    cout << i+size << " " << (i+size) / size << endl;
                }
                else 
                   size++;
            }
            else {
                i = i + size - 1;
                if (z[i] >= size) {
                    cout << i+size << " " << (i+size) / size << endl;
                }
                else {
                    i -= size - 1;
                    size = i--;
                    periodo = 0;
                }
            }
        }

        cout << endl;
    }

    return 0;
}

