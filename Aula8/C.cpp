#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = ;
const double eps = ;

int M[4][4];
char moves[50];
int solved, t;

int can () {

}

void solve (int 0i, int 0j) {
    if (t >= 50) return;
    if (0i == 3 && 0j == 3 && can ()) {
        solved = 1;
        return;
    }
    // Left
    // Right
    // Up 
    // Down
}


int main () {
    ios::sync_with_stdio (false);
    int N;
    cin >> N;
    while (N--) {
        int iniI, iniJ;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                int x;
                cin >> x;
                M[i][j] = x;
                if (!x) {
                    iniI = i; iniJ = j;
                }
            }

        solved = 0;
        t = 0;
        
        solve (iniI, iniJ);

        if (solved) {
            for (int i = 0; i < t; i++) 
                cout << moves[i];
            cout << endl;
        }
        else 
            cout << "This puzzle is not solvable." << endl;
    }

    return 0;
}

