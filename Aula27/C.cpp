#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int n;
pii v[504], aux[504];
int ans[504];
int sz;

int isSeq (int it) {
    for (int i = 0; i < it; i++)
        cout << aux[i].second << " ";
    cout << endl;
    if (it % 2 != 0) return 0;
    for (int i = 0; i < it / 2; i++) 
        if (aux[i].second != aux[it-1-i].second ||aux[i].first == aux[i+1].first) return 0;
    return 1;

}

int main () {
    scanf ("%d", &n);

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf ("%d %d", &x, &y);    
        v[i] = make_pair (x, i+1);
        v[n+i] = make_pair (y, i+1);
    }
    sort (v, v + 2*n); 
    for (int i = 0; i < 2*n; i++) {
        cout << "Inicio: " << i << endl;
        aux[0] = v[i];
        int it = 1;
        for (int j = i+1; j < 2*n && v[j].second != aux[0].second; j++) 
            aux[it++] = v[j];  
        aux[it++] = aux[0]; 
        if (isSeq (it) && it > sz) {
            for (int j = 0; j < it; j++)
                ans[j] = aux[j].second;
            sz = it;
        }
    }
    printf ("%d\n", sz / 2);
    for (int j = sz/2 - 1; j >= 0; j--)
        printf ("%d ", ans[j]);
    printf ("\n");

    return 0;
}

