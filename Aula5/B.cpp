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
    string s;
    cin >> s;
    int n = s.size ();

    vector<int> poss;
    int freq[MAX+5];

    // Z algorithm
    int z[MAX + 5];
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
       if (i > r) { 
           l = r = i;
           while (r < n && s[r-l] == s[r]) r++;
           z[i] = r - l;
           r--;
       }
       else {
           int k = i - l;
           if (z[k] < r - i + 1) 
               z[i] = z[k];
           else {
               l = i;
               while (r < n && s[r-l] == s[r]) r++;
               z[i] = r - l;
               r--;
           }
       }
       freq[z[i]]++;
       if (z[i] == n - i) poss.pb (n - i);
    }
    
    //Acumulate frequencies
    for (int i = n-1; i > 0; i--) 
        freq[i-1] += freq[i];
    for (int i = 0; i < poss.size (); i++) {
        int p = poss[i];
        //cout << p << " freq: " << freq[p] << endl;
        if (freq[p] >= 2) {
            cout << s.substr (0, p) << endl;
            return 0;
        }
    }
    cout << "Just a legend" << endl;

    return 0;
}

