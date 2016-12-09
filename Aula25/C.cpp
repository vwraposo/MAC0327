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

stack<char> st;
int ans;

int open (char c) {
    return (c == '<' || c == '(' || c == '[' || c == '{');
}

int close (char c) {
    return (c == '>' || c == ')' || c == ']' || c == '}');
}

int equals (char c, char s) {
    return (c == '<' && s == '>' || c == '[' && s == ']' || c == '(' && s == ')' || c == '{' && s == '}');
}

int main () {
    ios::sync_with_stdio (false);
    string s;
    cin >> s;
    int l = s.size ();
    for (int i = 0; i < l; i++) {
        if (!st.empty () && close (s[i]) && open (st.top ())) {
            if (!equals (st.top () , s[i])) ans++;
            st.pop ();
        }
        else 
            st.push (s[i]);
    }
    if (!st.empty ()) 
        cout << "Impossible" << endl;
    else 
        cout << ans << endl;

    return 0;
}

