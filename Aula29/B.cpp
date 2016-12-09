#include <bits/stdc++.h>

using namespace std;

int primes[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
int s;
int n;


int main () {
    char ans[10];
    for (int i = 0; n < 20; i++) {
        printf ("%d\n", primes[i]);
        fflush (stdout);
        scanf ("%s", &ans);
        if (ans[0] == 'y') {
            s++;
            int a = primes[i];
            a *= a;
            if (a < 100) {
                printf ("%d\n", a);
                fflush (stdout);
                scanf ("%s", &ans);
                if (ans[0] == 'y') s++;
                n++;
            }
        }
        n++;

    }
    if (s <= 1)
        printf ("prime\n");
    else 
        printf ("composite\n");
    fflush (stdout);

    return 0;
}

