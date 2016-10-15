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
ll dp[MAX];
ll ct[MAX];
int a[MAX];
int n;
int mx = 0;

int main () {
    ios::sync_with_stdio (false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > mx) mx = x;
        ct[x]++;
    }

    dp[0] = 0;
    dp[1] = ct[1];
    for (int i = 2; i <= mx; i++) {
        dp[i] = max (dp[i-1], dp[i-2] + i*ct[i]); 
    }
    cout << dp[mx] << endl;;

    return 0;
}

