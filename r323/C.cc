#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))

int gcd(int a, int b) {
    while(a) {
        int t = a;
        a = b % a;
        b = t;
    }
    return b;
}

int main() {
    int n, v;
    vector<int> a;
    priority_queue<int> pq, skip;

    S(n);

    FOR(i,0,n*n) {
        S(v);
        pq.push(v);
    }

    while(!pq.empty()) {
        v = pq.top(); pq.pop();

        if(!skip.empty() && v == skip.top()) {
            skip.pop();
            continue;
        }

        cout << v << " ";

        for(int prev : a) {
            int g = gcd(prev, v);
            //cout << "gcd(" << prev << ", " << v << ") = " << g << endl;
            skip.push(g);
            skip.push(g);
        }

        a.push_back(v);
    }
    cout << endl;

    return 0;
}
