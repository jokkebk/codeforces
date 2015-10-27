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

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))
#define ABS(a) (((a)<0) ? -(a) : (a))
#define SWAP(a,b) {a ^= b; b ^= a; a ^= b; }

#define Inf 1000000007

int main() {
    int n;

    cin >> n;

    vector<int> a(n+1), nums;
    vector<bool> used(n+1);

    FORE(i,1,n) {
        cin >> a[i];
        if(a[i]>n || used[a[i]]) a[i] = 0;
        used[a[i]] = true;
    }

    FORE(i,1,n) if(!used[i]) nums.push_back(i);
    FORE(i,1,n) if(!a[i]) a[i] = nums.back(), nums.pop_back();
    FORE(i,1,n) cout << a[i] << " "; cout << endl;

    return 0;
}
