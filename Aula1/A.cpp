#include <cstdio>

using namespace std;

int main () 
{
	int t, s, x;
	scanf ("%d %d %d", &t, &s, &x);
	if (x == t)
		printf ("YES\n");
	else {
		for (int i = 1; ; i++) {
			int time = t + i*s;
			if (x == time || x == time + 1) {
				printf ("YES\n");
				break;
			}	
			else if (x < time+1) {
				printf ("NO\n");
				break;
			}
		}
	}
	
	return 0;
}
