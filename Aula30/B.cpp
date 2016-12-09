#include <bits/stdc++.h>
#define pb push_back

using namespace std;

vector <string> v;
set<string> st;

int main () {
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        v.pb (s);
    }
    for (int i = v.size () - 1; i > -1; i--) {
        if (st.find (v[i]) == st.end ()) {
            st.insert (v[i]);
            cout << v[i] << endl;
        }
    }

}

