#include <cstdio>
#include <iostream>
#define MOD 1000000007

using namespace std;

long long  pot (long long x, long long e) { 
    if (e == 0) return 1;
    if (e % 2 == 0) {
        long long b = ((x % MOD) * (x % MOD)) % MOD;
        return pot (b, e / 2) % MOD;
    }
else 
        return ((x % MOD) * (pot (x, e-1) % MOD) ) % MOD;
}

int main () {
    long long A, B, x;
    long long n;
    cin >> A >> B >> n >> x;
    long long An = pot (A, n);
    //cout << An << endl;
    long long PG = n % MOD;
    if (A != 1)
        PG = ((An - 1) * pot (A - 1, MOD - 2)) % MOD;
    //cout << PG << endl;

    long long ans = ((x * An) % MOD + (B * (PG % MOD)) % MOD) % MOD;

    cout << ans << endl;
    return 0;
}
