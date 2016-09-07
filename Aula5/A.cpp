#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 2000;

char s[MAX+5];
char aux[3] = {'c', 'b' , 'a'};
int N;

int palindrome (int i) {
    int j;
    if (i == N && i < 3) {
        for (j = 0; j < i; j++)
            s[j] = 'a';
        s[j] = '\0';
        return 1;
    }
    else if (i > 2) {
        for (j = 0; j < min (i - 2, N); j++)
            s[j] = 'a';
        int l = 0;
        for (; j < N; j++)
            s[j] = aux[l++%3];
        s[j] = '\0';
        return 1;
    }
    return 0;
}

int main () {
    ios::sync_with_stdio (false);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cout << i << " : ";
        if (palindrome (i))
            cout << s << endl;
        else 
            cout << "NO" << endl;
    }

    return 0; 
}

