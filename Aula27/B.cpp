#include<bits/stdc++.h>

using namespace std;

const int MAX = 100000;

int c[MAX];
int t[MAX];
int r[MAX];

int n, m;

int bb (int val, int b = 0, int e = m) {
    if (b == e-1) {
        if (e == m)
            return b;
        else 
            return abs (val - t[b]) < abs (val - t[b+1]) ? b : b+1;
    }

    int mid = (b + e) / 2;
    if (val < t[mid])  
        return bb (val, b, mid);
    else
        return bb (val, mid, e);
}

int main () {
    scanf ("%d %d", &n, &m);
    int ans = 0;

    for (int i = 0; i < n; i++) scanf ("%d", &c[i]);
    for (int i = 0; i < m; i++) scanf ("%d", &t[i]);

    for (int i = 0; i < n; i++) {
        int b_t = bb (c[i]); 
        int b_d = abs (c[i] - t[b_t]);
        //cout << "Cidade: " << i << " Torre: " << b_t << "Dist: " << b_d << endl;
        r[b_t] = max (r[b_t], b_d);
    }
    for (int i = 0; i < m; i++) {
        //cout << "Torre : " << i << " Raio: " << r[i] << endl;
        ans = max (ans, r[i]);
    }

    printf ("%d\n", ans);


}

