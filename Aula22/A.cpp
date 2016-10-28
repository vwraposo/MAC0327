#include <bits/stdc++.h>

using namespace std;

const int MAX = 40005;
int memo[MAX];
int n, a, b, c;

int dp (int s) {
    if (s == 0) return 0;
    if (s < 0) return INT_MIN;

    if (memo[s] != -1) return memo[s];

    int A, B, C;
    A = B = C = INT_MIN;
    if (s-a >= 0) 
        A = dp (s-a) + 1;
    if (s-b >= 0)
        B = dp (s-b) + 1;
    if (s-c >= 0)
        C = dp (s-c) + 1;

    return memo[s]= max (A, max (B, C)); 

}

int main () {
    memset (memo, -1, sizeof(memo));
    scanf ("%d %d %d %d", &n, &a, &b, &c);
    printf ("%d\n", dp (n));
}

