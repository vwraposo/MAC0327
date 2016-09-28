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


int cube[8][3];
ll l;

ll distance (int a, int b) {
    ll distx = cube[a][0] - cube[b][0];
    ll disty = cube[a][1] - cube[b][1];
    ll distz = cube[a][2] - cube[b][2];
    
    return (distx*distx + disty*disty + distz*distz);
}

int isCube () {
    vector<ll> dist;
    for (int i = 0; i < 8; i++) {
        dist.clr;
        for (int j = 0; j < 8; j++) {
            if (j == i) continue;
            ll d = distance (i, j);
            if (d == 0) return 0;
            dist.pb (d);
        }
        sort (dist.begin (), dist.end ());
        if (i == 0)
            l = dist[0];

        for (int j = 0; j < 3; j++)
            if (dist[j] != l) return 0;
        for (int j = 3; j < 6; j++)
            if (dist[j] != l*2) return 0;
        if (dist[6] != l*3) return 0;
    }

    return 1;
}

int restore (int c) {
    if (c == 8) 
        return isCube ();

    do {
        if (restore (c+1)) return 1;
    } while (next_permutation (cube[c], cube[c]+3));

    return 0;
}

int main () {
    ios::sync_with_stdio (false);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            cube[i][j] = x;
        }
        sort (cube[i], cube[i]+3);
    }

    if (restore (0)) {
        cout << "YES" << endl;
        for (int i = 0; i < 8; i++) 
            cout << cube[i][0] << " " << cube[i][1] << " " << cube[i][2] << endl;
    }
    else 
        cout << "NO" << endl;

    return 0;
}

