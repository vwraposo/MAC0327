#include <cstdio>

using namespace std;

int N;

long long  bb (int digit, int begin, int end) {
    if (begin >= end-1) return begin;
    long long n = begin / 2 + end / 2;
    long long an = n * (n + 1) / 2;
    if (an == digit) return n;
    if (digit > an)
        return bb (digit, n+1, end);
    else 
        return bb (digit, begin, n);
}

int main () {
	scanf ("%d", &N);
	for (int i = 0; i < N; i++) {
		int  digit; 
		scanf ("%d", &digit);
                digit--;
                long long  ans = bb (digit, 0, digit+1);
		if (digit == ans * (ans + 1) / 2)
			printf ("1 ");
		else 
			printf ("0 ");
	}
	printf ("\n");

	return 0;
}
