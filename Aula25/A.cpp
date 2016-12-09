#include<bits/stdc++.h>

using namespace std;

int main () {
    string s;
    int n;
    cin >> n;
    getline (cin, s);
    for (int i = 0; i < n; i++) {
        getline (cin, s);
        stack<char> st;
        //cout << "Teste: " << i << " String: " << s << endl;

        int l = s.size ();
        for (int j = 0; j < l; j++) {
            if (s[j] == ' ') continue;
            if (!st.empty () && (s[j] == ')' && st.top () == '(' || s[j] == ']' && st.top () == '[')) {
                st.pop ();
            }
            else {
                st.push (s[j]);
            }
        }
        if (st.empty ())
            printf ("Yes\n");
        else 
            printf ("No\n");
    }

    return 0;
}
