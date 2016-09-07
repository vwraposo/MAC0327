#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main () {
    ios::sync_with_stdio (false);
    string a, b;
    cin >> a >> b;
    int szA = a.size (), szB = b.size ();
    int iA = 0, iB = 0; 
    // 0 - a == b
    // 1 - a > b
    // 2 - b > a
    int ans = 0;
    if (szA > szB)
        while (iA < szA - szB) {
            if (a[iA] != '0') ans = 1;
            iA++;
        }
    else if (szB > szA)
        while (iB < szB - szA) {
            if (b[iB] != '0') ans = 2;
            iB++;
        }
    for ( ;!ans && iA < szA && iB < szB; iA++, iB++) {
        int numA = a[iA] - '0';
        int numB = b[iB] - '0';
        //debug("iA%d: %d, iB %d: %d\n", iA, numA, iB, numB);
        if (numA > numB) ans = 1;
        else if (numB > numA) ans = 2;
    }
    switch (ans) {
        case 1: 
            cout << ">" << endl;
            break;
        case 2:
            cout << "<" << endl;
            break;
        case 0:
            cout << "=" << endl;
            break;
    }

    return 0;

}

