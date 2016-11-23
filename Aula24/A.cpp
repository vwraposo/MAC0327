#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;
const double pi = acos (-1);

struct na{
    double x, y;
} nails[MAX];

double calculate (int i, int j) {
    double dx = nails[i].x - nails[j].x;
    double dy = nails[i].y - nails[j].y;

    return sqrt (dx*dx + dy*dy);
}


int main () {
    int n; 
    double r;
    double ansR = 0;
    scanf ("%d %lf", &n, &r);
    for (int i = 0; i < n; i++) {
        double px, py;
        scanf ("%lf %lf", &px, &py);
        nails[i].x = px;
        nails[i].y = py;
    }
    for (int i = 1; i < n; i++) {
        ansR += calculate (i, i-1); 
    }
    ansR += calculate (0, n-1);
    printf ("%.2lf\n", ansR + 2*pi*r);


    return 0;
}

