#include <cstdio>
#include <cstring>

using namespace std;

char str[105];
char num[3];

int main () {
    int sz;
    scanf ("%s", str);
    sz = strlen (str);
    for (int n = 0; n < 1000; n += 8) {
        int j = 0;
        num[0] = n / 100 + '0';
        if (num[0] == '0') j++;
        num[1] = (n / 10) % 10 + '0';
        if (j == 1 && num[1] == '0') j++;
        num[2] = n % 10 + '0';
          
        for (int i = 0; i < sz; i++) { 
            if (str[i] == num[j]) j++;
            if (j == 3) {
                printf ("YES\n");
                for (int k = 0; k < 2; k++) 
                    if (num[k] != '0')  printf ("%c", num[k]);
                printf ("%c\n", num[2]);
                return 0;
            }
        }
    }
    printf ("NO\n");
    return 0;
}
