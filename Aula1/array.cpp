#include <cstdio>
#include <set>

using namespace std;

int N;
int s1 = 0;
int s2[2];

int main () { 
    set<int> s3;
    set<int>::iterator it;

    scanf ("%d", &N);
    for (int i = 0; i < N; i++) {
        int x;
        scanf ("%d", &x);
        if (x < 0 && s1 == 0) 
            s1 = x;
        else if (x > 0 && s2[0] == 0) 
            s2[0] = x;
        else 
            s3.insert (x);
    }
    printf ("1 %d\n", s1);
    if (s2[0] == 0) {
        printf ("2 ");
        it = s3.begin ();
        s3.erase (*it);
        printf ("%d ", *it);
        it = s3.begin ();
        s3.erase (*it);
        printf ("%d\n", *it);
    }
    else 
        printf ("1 %d\n", s2[0]);

    printf ("%d ", s3.size ()); 
    for (it = s3.begin (); it != s3.end (); it++) 
        printf ("%d ", *it); 
    printf ("\n");
    return 0;
}
