#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100000;

int freq[MAX+5];
int ans = 0;

int main () {
    ios::sync_with_stdio (false);
    string s;
    cin >> s;
    int n = s.size ();

    int l = 0, r = 0;
    int z[MAX+5];
    z[0] = n;
    freq[n]++;
    ans++;
    for (int i = 1; i < n; i++) {
        if (i > r) {
            l = r = i;
            while (r < n && s[r-l] == s[r]) r++;
            z[i] = r - l; r--;
        }
        else {
            int k = i - l;
            if (z[k] < r - i + 1) z[i] = z[k];
            else {
                l = i;
                while (r < n && s[r-l] == s[r]) r++;
                z[i] = r - l; r--;
            }
        }
        freq[z[i]]++;
        if (z[i] == n - i) ans++;
    }
    // freq absoluta
    for (int i = n; i > 1; i--)
        freq[i-1] += freq[i];

    cout << ans << endl;
    for (int i = n-1; i >= 0; i--)
        if (z[i] == n - i) 
            cout << n - i << " " << freq[n-i] << endl;


}

