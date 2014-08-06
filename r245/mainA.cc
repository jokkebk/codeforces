#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(n) for(int _i=n; _i>0; --_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

int main() {
    vector<int> v, vs;
    map<int,int> col;
    int n, m, c = 0;

    cin >> n >> m;

    v.resize(n);
    FOR(i,0,n)
        cin >> v[i];

    vs = v;
    sort(vs.begin(), vs.end());

    for(int val : vs)
        col[val] = (c++) & 1;

    for(int val : v)
        cout << col[val] << ((val == v[n-1]) ? "" : " ");

    return 0;
}
