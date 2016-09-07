#include <cstdio>
#include <vector>

using namespace std;

int C, T;
vector <long long> a;
long long score = 0;

int main () {
    scanf ("%d %d", &C, &T);
    for (int i = 0; i < C; i++) {
        int x;
        scanf ("%d", &x);
        a.push_back ((long long ) x*x);
    }
    for (int i = 0; i < T; i++) {
        long long  x, y;
        scanf ("%lld %lld", &x, &y);
        long long  r = x*x + y*y;
        vector<long long>::iterator low = lower_bound (a.begin (), a.end (), r); 
        score += (C) - (low - a.begin ()); 
    }
    printf ("%lld\n", score);

    return 0;
}
