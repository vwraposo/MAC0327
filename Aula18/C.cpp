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

int N, K, S;
int memo[25][15][157];

int dp (int n, int k, int s) {
    if (n > N+1 || s > S || k > K) 
        return 0;
    if (k == K) { 
        if (s == S) return 1; 
        return 0;
    }

    if (memo[n][k][s] != -1) 
        return memo[n][k][s];


    return memo[n][k][s] = dp (n+1, k, s) + dp (n+1, k+1, s+n);
}

int main () {
    ios::sync_with_stdio (false);
    cin >> N >> K >> S;
    while (N && K && S) {
        mem(memo, -1);

        cout << dp (1, 0, 0) << endl;

        cin >> N >> K >> S;
    }

}


