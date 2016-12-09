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

const int MAX = 1000000000;

int v[100005];
ll p[100005];
map <int, int> freq, ex;
ll ans;

int main () {
    ios::sync_with_stdio (false);
    ll x = 2;
    int cnt = 0;
    while (x < 2*MAX + 10) {
        p[cnt++] = x;
        x *= 2;
        cnt++;
    }
    int n; 
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        freq[v[i]]++;
        ex[v[i]] = 1;
    }
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < cnt; j++) {
           x = p[j] - v[i];
           if (ex[x]) { 
               if (x == v[i]) 
                   ans += freq[x] - 1;
               else 
                   ans += freq[x];
           }
        }

    cout << ans / 2<< endl;

    return 0;
}

