#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;


set<pii> st;

int mdc (int a, int b) {
    return b ? mdc (b, a%b) : a;
}

int main () {
    int n, xo, yo;
    scanf ("%d %d %d", &n, &xo, &yo);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf ("%d %d", &x, &y);
        y -= yo;
        x -= xo;
        int d = x ? mdc (x, y) : y;
        y /= d;
        x /= d;
        st.insert (pii (y, x));
    }
    printf ("%d\n", st.size ());

    return 0;   
}

