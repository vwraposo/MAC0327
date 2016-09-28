#include <bits/stdc++.h>

using namespace std; 

int n, q;
string rules[40][2];
int ans;

void f (char l, int t) {
    if (t == 0) {
        if (l == 'a') ans++; 
        return;
    }

    for (int i = 0; i < q; i++) {
        string s = rules[i][0];
        if (s[0] == l) {
            f (rules[i][1][0], t-1);
        }
    }
}

int main () {
    ios::sync_with_stdio (false);
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        rules[i][0] = s;
        cin >> s;
        rules[i][1] = s;
    }
    char l;
    for (int i = 0; i < 6; i++) {
        l = 'a' + i;
        f (l, n-1);
    }

    cout << ans << endl;

    return 0;
}
