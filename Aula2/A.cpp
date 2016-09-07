#include <set>
#include <cstdio>

using namespace std;

set<int> lant;
set<int>::iterator it;
set<double> dist;
int L, N;

int main () {
    scanf ("%d %d", &N, &L);
    for (int i = 0; i <  N; i++) {
        int x;
        scanf ("%d", &x);
        lant.insert (x);
    }
    int ant = *lant.begin ();
    dist.insert (ant); 
    it = lant.begin ();
    it++;
    for ( ; it != lant.end (); it++) { 
        int d = *it - ant;
        //printf ("%`f\n", (double) d/2);
        dist.insert ((double) d / 2);
        ant = *it;
    }
    dist.insert (L - *lant.rbegin ());
    double d = *dist.rbegin ();
    printf ("%.10lf\n", d);

    return 0;
}
