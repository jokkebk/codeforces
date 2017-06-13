#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> mn[32];
    int n, q, m, i, j;
    string s;
    char c;

    cin >> n >> s >> q;

    for(c = 'a'; c <= 'z'; c++) {
        mn[c-'a'].resize(n+1);
        for(i=0; i<n; i++) {
            for(j=i, m=0; j<n; j++) {
                if(s[j] != c) m++;
                mn[c-'a'][m] = max(mn[c-'a'][m], j-i+1);
            }
        }
        for(i=n; !mn[c-'a'][i]; i--) mn[c-'a'][i] = n;
    }

    while(q--) {
        cin >> m >> c;
        cout << mn[c-'a'][m] << endl;
    }
}
