#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unsigned long long N, number, complexity;
int primes[22] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79};

void solve (int p, long long divs, unsigned long long n, unsigned long long c) {
    if (c > complexity || (c == complexity && n < number)) {
        complexity = c;
        number = n;
    }
    if (p >= 22) return;

    for (ll i = 1; i <= divs && n <= N / primes[p]; i++) {
        //debug("%lld\n", n);
        n *= primes[p];

        solve (p+1, i, n, c * (i + 1));
    }
} 

int main () {
    ios::sync_with_stdio (false);
    int T; 
    cin >> T;
    while (T--) {
        cin >> N;

        number = complexity = 1;

        solve (0, 60, 1, 1);
        
        cout << number << " " << complexity << endl;
    }

}

