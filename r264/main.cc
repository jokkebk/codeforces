#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)

int before[1024][1024], s[5][1000], n, k;
vector<int> len(1000, 1), S;
vector<bool> visited(1000);
vector< vector<int> > adj(1000);

void recurseTopo(int i) {
    visited[i] = true;
    for(int j : adj[i]) if(!visited[j]) recurseTopo(j);
    S.push_back(i);
}

int main() {
    cin >> n >> k;

    FOR(i,0,n) memset(before[i], 0, 1024*sizeof(int));

    FOR(i,0,k) {
        FOR(j,0,n) {
            cin >> s[i][j];
            FOR(m,0,j) before[s[i][j]-1][s[i][m]-1]++;
        }
    }

    FOR(i,0,n) FOR(j,0,n) if(before[i][j] == k) adj[i].push_back(j);

    FOR(i,0,n) if(!visited[i]) recurseTopo(i);

    for(auto i = S.rbegin(); i != S.rend(); ++i)
        for(int j : adj[*i]) len[j] = max(len[j], len[*i]+1);

    cout << *max_element(len.begin(), len.end()) << endl;

    return 0;
}
