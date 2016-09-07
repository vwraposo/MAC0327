#include <cstdio>

using namespace std;

int N, K;

int main () {
    scanf ("%d %d", &N, &K);

    // p e a primeira potencia de 2 maior que K
    int p = 1, time = 0;

    while (p < K && p < N) {
        p *= 2;
        time++;
    }

    if (p < N) time += (N - p + K - 1) / K; 

    printf ("%d\n", time); 

    return 0;
}
