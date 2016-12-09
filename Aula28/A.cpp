#include <bits/stdc++.h>

using namespace std;

const int MAX = 100005;

int v[MAX];
int n;
int t;

int main () {
    scanf ("%d %d", &n, &t);
    for (int i = 1; i < n; i++) 
        scanf ("%d", &v[i]);

    for (int i = 1; i < n;) {
        if (t == i) {
            printf ("YES\n");
            return 0;
        }
        i += v[i];
    }
    if (t == n)
        printf ("YES\n");
    else 
        printf ("NO\n");

    return 0;
}

