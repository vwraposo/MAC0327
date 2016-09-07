#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)


using namespace std;

int const MAX = 1000000000;


long long  pot (long long x, long long e, int N) { 
    if (e == 0) return 1;
    if (e % 2 == 0) {
        long long b = ((x % N) * (x % N)) % N;
        return pot (b, e / 2, N) % N;
    }
else 
        return ((x % N) * (pot (x, e-1, N) % N) ) % N;
}

int main () {
     ios::sync_with_stdio (false);
     int T, N;
     cin >> T;
     while (T--) {
         cin >> N;
         int p  = N;
         for (int i = 2; i*i < N; i++) 
             if (p % i == 0)
                 p /= i;
         int q = N / p;
         long long x = q*pot (q, p-2, N);    
         long long y = p*pot (p, q-2, N);
         x = x % N;
         y = y % N;
         printf ("0 1 %lld %lld\n", min (x, y), max (x, y));
     }

    return 0;
}

