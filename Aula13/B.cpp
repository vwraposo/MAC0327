#include <bits/stdc++.h>

using namespace std;

int n, a, b, c, d;
int ans[2];

int main () {
    ios::sync_with_stdio (false);
    cin >> n >> a >> b >> c >> d;
    ans[0] = a + b + 1;
    ans[1] = a + b + n;

    int x;
    x = a + c + 1;
    if (x > ans[0]) ans[0] = x;
    x = a + c + n;
    if (x < ans[1]) ans[1] = x;

    x = d + c + 1;
    if (x > ans[0]) ans[0] = x;
    x = d + c + n;
    if (x < ans[1]) ans[1] = x;

    x = b + d + 1;
    if (x > ans[0]) ans[0] = x;
    x = b + d + n;
    if (x < ans[1]) ans[1] = x;

    long long r = ans[1] - ans[0] + 1;
    if (r < 0) r = 0;
    r *= n;

    cout << r << endl;

    return 0;
}

