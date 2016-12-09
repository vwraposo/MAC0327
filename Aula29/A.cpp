#include<bits/stdc++.h>

using namespace std;

priority_queue<int> q;
int lim;
int ans;

int main () {
    int n;
    scanf ("%d", &n);
    scanf ("%d", &lim);
    for (int i = 0; i < n-1; i++) {
        int x;
        scanf ("%d", &x);
        q.push (x);
    }
    while (q.top () >= lim) {
        int t = q.top ();
        q.pop ();
        ans++;
        lim ++;
        q.push (t-1);
    }

    printf ("%d\n", ans);

    return 0;
}

