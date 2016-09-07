#include <cstdio>
#include <cctype>

using namespace std;

char str[100];
int N;

int isIn (char c) {
	int ans = 0;
	for (int i = 0; i < N; i++)
		if (str[i] == c) ans = 1;
	
	return ans;
}	

int main () {
	int ans = 1;
	scanf ("%d %s", &N, str);

 	for (int i = 0; i < N; i++)
		str[i] = tolower (str[i]);

	for (char c = 'a'; c <= 'z'; c++)
		if (!isIn (c)) {
			ans = 0;
			break;
		}
	if (ans == 0) 
		printf ("NO\n");
	else 
		printf ("YES\n");

	return 0;		
}
