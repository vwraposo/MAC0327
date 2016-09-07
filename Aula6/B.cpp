#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

char str[10005];

int main () {
    int M;
    scanf ("%s", str);
    scanf ("%d", &M);
    while (M--) {
        int l, r, k;
        scanf ("%d %d %d", &l, &r, &k);
        l--; r--; k = k % (r - l + 1);
        char aux[10005];
        int i = 0;
        for (int j = r-k+1; j <= r; j++)
            aux[i++] = str[j];
        for (int j = l; j <= r-k; j++)
            aux[i++] = str[j];
        for (int j = l, i = 0; j <= r; i++, j++)
            str[j] = aux[i]; 
    }
    printf ("%s\n", str);

    return 0;
}

