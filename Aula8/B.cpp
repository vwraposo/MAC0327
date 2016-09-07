#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SIZE = 16;
const int MAX = 1000;

int N;
vector <string> D;
int solved;
map<char, char> m;
string line;
vector<int> ans;

int strsz (int n) {
    int size = 0;
    for (int i = n; i < line.size () ; i++) {
        if (line[i] == ' ') return size;
        size++;
    }
    return size;
}

void solve (int begin, int size) {
    if (begin >= line.size ()) {
        solved = 1;
        return;
    }

    
    for (int s = 0; s < N; s++) {
        if (D[s].size() != size) continue;
        debug("-------------------------------------------\n");

        int conflicts = 0;
        vector<char> used;
        for (int i = 0; i < size; i++) {
            if (m.find (D[s][i]) != m.end ()) {
               if (m[D[s][i]] != line[begin+i]) {
                   conflicts = 1;
                   break;
               }
            }
            else { 
                used.pb (D[s][i]);
                m.insert (pair<char, char> (D[s][i], line[begin+i]));
            }
        }
        if (conflicts) {
            for (int i = 0; i < used.size (); i++) 
                m.erase (used[i]);
            continue;
        }
        
        ans.pb (s);
        solve (size+1, strsz (size+1));
        if (solved) return;
    }
}

int main () {
    ios::sync_with_stdio (false);
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        D.pb (s);
    }
        
    getline (cin, line);

    while (getline (cin, line)) { 
        if (line.size () == 0) {
            cout << endl;
            continue;
        }
        
        solved = 0;
        m.clear ();
        ans.clear ();

        solve (0, strsz (0));

        if (solved) 
            for (int i = 0; i < ans.size (); i++) 
                cout << D[ans[i]] << " ";
        else 
            for (int i = 0; i < line.size (); i++) {
                if (line[i] == ' ') cout << line[i]; 
                else cout << "*";
            }
        cout << endl;
    }

    return 0;
}

