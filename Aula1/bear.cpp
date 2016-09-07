#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N, K;
char str[100005];
int maxD;
char maxC;

void maxDist (char a) {
    int da, dz;
    da = abs (a - 'a'); 
    dz = abs (a -'z');
    maxD = max (da, dz);
    maxC = (da > dz) ? 'a' : 'z'; 
}

int main () {
    scanf ("%d %d", &N, &K);
    int M = 0;
    char c;
    scanf ("%c", &c);
    for (int i = 0; i < N; i++) {
        scanf ("%c", &c);
        maxDist (c);
        M += maxD;
        str[i] = c;
    }
    if (M >= K) {
        for (int i = 0; i < N; i++) {
            maxDist (str[i]);
            if (K > maxD) {
                str[i] = maxC;
                K -= maxD;
            }
            else {
                str[i] = (maxC == 'z') ? str[i] + K : str[i] - K;
                break;
            }
        }
        printf ("%s\n", str);
    }
    else 
        printf ("-1\n");
}
