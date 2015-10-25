#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))
#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define SWAP(a,b) {a ^= b; b ^= a; a ^= b; }

typedef long long LL;

int main() {
    int n;

    S(n);

    vector<int> p(n);

    FOR(i,0,n) cin >> p[i], p[i]--;

    map<int,vector<int>> start;
    vector<bool> done(n);
    bool odds=false;

    // Find cycles and mark done
    FOR(i,0,n) {
        if(done[i]) continue;
        int j=i, len=0;
        do {
            done[j] = true;
            len++;
            j = p[j];
        } while(j != i);
        if(len>2 && (len&1)) odds = true;
        start[len].push_back(i);
    }
    
    if(start.count(1)) {
        int center = start[1][0];
        cout << "YES" << endl;
        FOR(i,0,n) if(i != center) cout << center+1 << " " << i+1 << endl;
    } else if(start.count(2) && !odds) {
        int left = start[2][0], right = p[left];
        cout << "YES" << endl;
        cout << left+1 << " " << right+1 << endl;
        // Connect cycles with left, right and clear done
        FOR(i,0,n) {
            if(!done[i] || i==left || i==right) continue; // processed
            int j=i;
            do {
                cout << left+1 << " " << j+1 << endl;
                SWAP(left, right);
                j = p[j];
                done[j] = false;
            } while(j != i);
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
