#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

int a[100], n, b[100], best = 3000, ones[101], ok[60][60];

void recurse(int *res, int *S, int len, int level) {
    int *S2 = S + len, sum = ones[n-level];

    FOR(i,0,level) sum += abs(a[n-level+i] - res[i]);

    if(sum < best) {
        FOR(i,0,n-level) b[i] = 1;
        FOR(i,0,level) b[n-level+i] = res[i];
        best = sum;
    }

    if(level < n) FOR(i,0,len) { // recurse more numbers
        int num = 0;

        FOR(j,i+1,len)
            if(ok[S[i]][S[j]])
                S2[num++] = S[j];

        res[level] = S[i];
        recurse(res, S2, num, level+1);
    }
}

int main() {
	int a2[100], res[20], S[1000], len = 0, factor[60];
    map<int,vector<int>> ans;

    FOR(i,1,60) { // mark pairs with gcd == 1
        FOR(j,1,60) {
            ok[i][j] = (i == j) ? 0 : 1;
            FOR(k,2,29)
                if(i%k == 0 && j%k == 0) {
                    ok[i][j] = 0;
                    break;
                }
        }
    }

    FOR(i,1,60) factor[i] = 0;
    FOR(i,2,60) // mark largest factor
        for(int j=2; i*j < 60; j++)
            factor[i*j] = i;

    FOR(i,2,60) // push potential numbers
        if(i <= 30 || i - 30 < abs(30-factor[i]))
            S[len++] = i;

	cin >> n;
    FOR(i,0,n) cin >> a[i], a2[i] = a[i];

    sort(a, a + n); // sort the one used in solving

    ones[0] = 0; // calculate distance from series of ones
    FORE(i,1,n) ones[i] = ones[i-1] + a[i-1] - 1;

    recurse(res, S, len, 0);

    FOR(i,0,n) ans[a[i]].push_back(b[i]); // build answer lookup

    FOR(i,0,n) { // use lookup to print in original order
        cout << ans[a2[i]].back() << " ";
        ans[a2[i]].pop_back();
    }

    return 0;
}
