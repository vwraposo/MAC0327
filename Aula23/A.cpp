#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    int ans = -1;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf ("%d %d", &x, &y);
        ans = max (ans, x*x + y*y);
    }

    printf ("0 0 %.10f\n", sqrt (ans)); 

    return 0;
}

