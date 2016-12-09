#include <bits/stdc++.h>
#define mem(x,val) memset((x), (val), sizeof (x));
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define clr clear()
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 10005;

int key[MAX];
int l[MAX];
int r[MAX];
int cont;

void insert (int x, int pos = 0) {
    if (x == 0) return;
    if (key[x] > key[pos]) {
        if (r[pos] == -1) {
            r[pos] = x;
            return;
        }
        else {
            insert (x, r[pos]);
        }
    }
    else {
        if (l[pos] == -1) {
            l[pos] = x;
            return;
        }
        else {
            insert (x, l[pos]);
        }
    }
}

void post (int pos = 0) {
    if (pos == -1) return;
    post (l[pos]);
    post (r[pos]);
    printf ("%d\n", key[pos]);
}

int main () {
    ios::sync_with_stdio (false);
    int x;
    while (scanf ("%d", &x) != EOF) {
        key[cont] = x;
        l[cont] = -1;
        r[cont] = -1;
        insert (cont++);
    }

    post ();

    return 0;
}
