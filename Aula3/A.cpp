#include <cstdio>
#include <cmath>

using namespace std;

int gdc (int a, int b) {
    if (b == 0) return a;
    return gdc (b, a%b);
}

int main () {
    int T;
    scanf ("%d", &T);
    while (T--) {
        int x1, x2, y1, y2;
        scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);
        int x = abs (x1 - x2);
        int y = abs (y1 - y2);
        if (x == 0)
            printf ("%d\n", y + 1);
        else if (y == 0)
            printf ("%d\n", x + 1);
        else {
            int ans = gdc (x, y) + 1;
            printf ("%d\n", ans);
        }
    }

    return 0;
}
