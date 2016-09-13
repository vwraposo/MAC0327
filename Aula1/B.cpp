#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

char str[55];
queue<int> q;

int main () {
    int sz, mod = 0;
    scanf ("%s", &str);
    sz = strlen (str);
    for (int i = 0; i < sz; i++)
        q.push (str[i] - '0');
    while (!q.empty()) {
        mod *= 10;
        mod += q.front ();
        q.pop ();
        mod %= 7;
    }

    printf ("%d\n", mod);

    return 0;
}
