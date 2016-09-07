#include <cstdio>
#include <vector>
#define MAX 100000

using namespace std;

int p[100010];

int main () {
    for (int i = 2; i <= MAX; i++)
        if (!p[i]) {
            for (int j = 2*i; j <= MAX; j+= i) 
                p[j] = 1;
        }

    int T;
    scanf ("%d", &T);
    for (int i = 0; i < T; i++) {
        int N, K;
        scanf ("%d %d", &N, &K);
        long long ans = 0;
        int first = 2, last = 2, k = 1;
        while (last <= N) {
            //printf ("first: %d, last: %d, k; %d, ans: %lld\n", first, last, k, ans);
            if (k >= K) {
                ans += 1 + N - last;
                if (!p[first]) k--;
                first++;
            }
            else {
                last++;
                if (!p[last]) k++;
            }
            if (first > last) {
                last = first;
                if (!p[last]) k++;
            }
        }

        printf ("%lld\n", ans);
    }

    return 0;
}
