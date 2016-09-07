#include <cstdio>

using namespace std;


long long pot (long long b, long long e, long long m) {
    if (e == 0) return 1;
    if (e % 2 == 0) {
        long long x = ((b%m) * b%m)%m;
        return pot (x,e/2, m); 
    }
    else {
        long long x = ((b%m)*(pot (b, e-1,m)%m))%m;
        return x;
    }
}
int main () {
    int K;
    scanf ("%d", &K);
    //printf ("AQUI\n");
    for (int i = 1; i <= K; i++) {
        long long B, E, M;
        scanf ("%lld %lld %lld", &B, &E, &M);
        printf ("%d. %lld\n", i, pot (B, E, M));
    }
}
