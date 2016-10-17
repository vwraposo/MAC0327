#include <bits/stdc++.h>
#define mem(x,val) memset((x), (val), sizeof (x));
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define clr clear()
#define debug(args...) //fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

long double x, y, z;
long double mx;
int ans;

int main () {
    ios::sync_with_stdio (false);

    cin >> x >> y >> z;
    mx = INT_MIN;
    long double val;
    
    // 1
    val = pow (y, z) * log (x);
    debug("1 %Lf\n", val);
    if (val > mx) {
        mx = val;
        ans = 1;
    }
    // 2
    val = pow (z, y) * log (x);
    debug("2 %Lf\n", val);
    if (val > mx) {
        mx = val;
        ans = 2;
    }
    // 3
    val = y*z*log (x); 
    debug("3 %Lf\n", val);
    if (val > mx) {
        mx = val;
        ans = 3;
    }
    // 5
    val = pow (x, z) * log (y);
    debug("5 %Lf\n", val);
    if (val > mx) {
        mx = val;
        ans = 5;
    }
    // 6
    val = pow (z, x) * log (y);
    debug("6 %Lf\n", val);
    if (val > mx) {
        mx = val;
        ans = 6;
    }
    // 7
    val = x*z*log (y); 
    debug("7 %Lf\n", val);
    if (val > mx) {
        mx = val;
        ans = 7;
    }
    // 9
    val = pow (x, y) * log (z);
    debug("9 %Lf\n", val);
    if (val > mx) {
        mx = val;
        ans = 9;
    }
    // 10
    val = pow (y, x) * log (z);
    debug("10 %Lf\n", val);
    if (val > mx) {
        mx = val;
        ans = 10;
    }
    // 11
    val = x*y*log (z); 
    debug("11 %Lf\n", val);
    if (val > mx) {
        mx = val;
        ans = 11;
    }

    switch (ans) {
        case 1:
            cout << "x^y^z" << endl;
            break;
        case 2:
            cout << "x^z^y" << endl;
            break;
        case 3:
            cout << "(x^y)^z" << endl;
            break;
        case 5:
            cout << "y^x^z" << endl;
            break;
        case 6:
            cout << "y^z^x" << endl;
            break;
        case 7:
            cout << "(y^x)^z" << endl;
            break;
        case 9:
            cout << "z^x^y" << endl;
            break;
        case 10:
            cout << "z^y^x" << endl;
            break;
        case 11:
            cout << "(z^x)^y" << endl;
            break;
    }

}

