#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)

using namespace std;

const int MOD = 1000000007;

vector<int> p;
int a[200000];

long long pot (long long x, long long e) {
    if (e == 0) return 1;
    if (e % 2 == 0) {
        long long b = (x * x) % MOD;
        return pot (b, e/2) % MOD; 
    }
    else { 
        long long b = (x * x) % MOD;
        return (x *  (pot (b, e / 2) % MOD)) % MOD;
    }
}

int main () {
    ios::sync_with_stdio (false);
    int X = 1;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (!a[x]) {
            p.push_back (x);
            a[x] = 1;
        }
        else 
            a[x]++;
    }
    for (int i = 0; i < p.size (); i++) 
        if (a[p[i]] % 2 != 0) X = 0;

    long long ans = 1;
    if (!X) {
        for (int i = 0; i < p.size (); i++) {
            long long b = pot (p[i], a[p[i]]) % MOD;
            ans = ((ans % MOD) * (b % MOD)) % MOD;
        }
        int done = 0;
        for (int i = 0; i < p.size (); i++) {
            int alpha = (a[p[i]] + 1);
            if (!done && a[p[i]] % 2 != 0) {
                done = 1;
                alpha /= 2;
            }
            ans = pot (ans, alpha) % MOD;
        }
    }
    else {
        for (int i = 0; i < p.size (); i++) {
            long long b = pot (p[i], a[p[i]] / 2) % MOD;
            ans = ((ans % MOD) * (b % MOD)) % MOD;
        }
        for (int i = 0; i < p.size (); i++) {
            int alpha = (a[p[i]] + 1);
            ans = pot (ans, alpha) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}

