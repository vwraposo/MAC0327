#include <bits/stdc++.h>

using namespace std;

int n, ans;
string s;
int v, h;

int main ()  {
    ios::sync_with_stdio (false);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        v = 0; h = 0;
        for (int j = i; j < n; j++) {
            switch (s[j]) {
                case 'U':
                    v++;
                    break;
                case 'D':
                    v--;
                    break;
                case 'R':
                    h++;
                    break;
                case 'L':
                    h--;
                    break;
            }
            if (v == 0 && h == 0) ans++;
        }
    }

    cout << ans << endl;

    return 0;   
}

