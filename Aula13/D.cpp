#include <bits/stdc++.h>
#define mem(x,val) memset((x), (val), sizeof (x));
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define clr clear()
#define FOR(i,a,b) for (int i = (a);i < (b); i++)
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = ;

typedef struct N{
    Node *left, *right;
} Node;

string s;
int it;

Node* build_graph () {
    if (s[it] == ',') it++;
    if (s[it] == ')') {
        it++;
        return NULL;
    }
    if (s[it] == '(') {
        Node *nw = malloc (sizeof (Node));
        it++;
        nw->left = build_graph ();
        nw->right = build_graph ();
    }
} 

int main () {
    ios::sync_with_stdio (false);
    while (cin >> s) {
        it = 0;
        Node *root = build_graph (); 
    }

}

