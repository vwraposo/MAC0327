#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {
    ll quant = 9;
    ll power = 10;
    ll dig = 1;
    int n;
    ll ans = 0;

    scanf ("%d", &n);

    while (1) {
        if (n > power - 1)
            ans += quant * dig;
        else {
            ans += (n-(power/10-1))*dig;
            break;
        }
        dig++;
        power *= 10;
        quant *= 10;
    }
    cout << ans << endl;

    return 0;
}

