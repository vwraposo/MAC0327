// vlgoritmo
//
// Soma acumulada e marca o mod N da soma, se S[i] % N = S[j] % N, i < j; basta pegar a soma acumulada de i+1 ate j
// pois tera mod N igual a zero
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <cstdio>
#include <cstring>

using namespace std;

int N;
int v[10005];
int m[10005];
int sum = 0;

int main () {
    scanf ("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf ("%d", &v[i]);

    memset (m, -1, sizeof (m));
    m[0] = 0;

    for (int i = 0; i < N; i++) {
        sum += v[i];

        if (m[sum%N] != -1) {
            printf ("%d\n", i+1 - m[sum%N]);
            for (int j = m[sum%N]; j <= i; j++) 
                printf ("%d\n", v[j]);
            break;
        }
        else
            m[sum%N] = i+1;
    }

    return 0;
}


