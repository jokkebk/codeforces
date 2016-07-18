#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))
#define fi first
#define se second

typedef long long LL;

#define Inf 1000000007

vector<vector<pair<int,int>>> to;
vector<LL> a;

void print(int v=0, int d=0) {
    static char indent[21] = "                    ";

    cout << v+1 << " = " << a[v] << endl;

    for(auto p : to[v]) {
        cout << &indent[18-d*2] << p.se << " -> ";
        print(p.fi, d+1);
    }
}

int rec(int v, int s=0, int m=0) {
    cout << "At " << v << " sum " << s << " max " << m << endl;

    if(m > a[v]) {
       cout << "Too much!" << endl;
       return 0;
    }

    int c = 1;
    for(auto p : to[v]) {
        c += rec(p.fi, s+p.se, max(m, s+p.se));
    }

    return c;
}

int main() {
    int n;

    cin >> n;

    a.resize(n);
    to.resize(n);

    FOR(i,0,n) cin >> a[i];

    FOR(i,1,n) {
        int p, c;
        cin >> p >> c;
        to[p-1].push_back(make_pair(i, c));
    }

    print();

    cout << n-rec(0) << endl;

    return 0;
}
