#include <bits/stdc++.h>

using namespace std;

const int MAX = 5005;

long long memo[MAX];
string s;
int n;

long long dp (int i) {
    if (i > n-1) return 1;
    if (s[i] == '0') return 0;

    if (memo[i] != -1) return memo[i];

    int ans = 0;
    int next = i+1 < n ? (s[i] - '0')*10 + (s[i+1] - '0') : 30; 
    if (next <= 26) 
        ans += dp (i+2);

    ans += dp (i+1);

    return memo[i] = ans;
}

int main () {   
    while (true) {
        memset (memo, -1, sizeof (memo));
        cin >> s;
        if (s[0] == '0') break;
        n = s.size ();
        printf ("%lld\n", dp (0));
    }

    return 0;
}

