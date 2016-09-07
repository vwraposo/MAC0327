#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 16;

int N;
int ans[MAX+5], used[MAX+5];

int isPrime (int A) {
    int divs = 2;
    for (int i = 2; i*i <= A; i++) {
        if (A % i == 0) divs++;
        if (divs > 2) return 0;
    }

    return 1;
}

void ring (int n) {
    if (n == N) {
        if (isPrime (ans[0] + ans[N-1])) {
            for (int i = 0; i < N-1; i++)
                cout << ans[i] << " ";
            cout << ans[N-1] << endl;
        }
        return;
    }

    for (int i = 2; i <= N; i++) {
        if (!used[i] && isPrime (i + ans[n-1])) {
            ans[n] = i;
            used[i] = 1;
            ring (n+1);
            used[i] = 0;
        }
    }

}

int main () {
    ios::sync_with_stdio (false);
    int i = 1;
    while (cin >> N) {
        if (i != 1) cout << endl; 
        cout << "Case " << i++ << ":" << endl;
        ans[0] = 1;
        memset (used, 0, N*sizeof (int));
        ring (1); 
    }

}


