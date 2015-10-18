#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))
#define SWAP(a,b) {a ^= b; b ^= a; a ^= b; }

#define Inf 1000000007

LL modpow(LL a, LL k, LL p) { // a^k % p
    LL ret = 1;
    while(k) {
        if(k % 2) ret = (ret * a) % p;
        k /= 2;
        a = (a * a) % p;
    }
    return ret;
}

int main() {
    LL n, l, k;

    cin >> n >> l >> k;

    vector<int> a(n);
    map<int,int> nums, rem;

    FOR(i,0,n) {
        S(a[i]);
        nums[a[i]]++;
        if(i < l%n) rem[a[i]]++;
    }

    vector<int> num, cnt, cum;

    LL s=0;
    for(auto& it : nums) {
        num.push_back(it.first);
        cnt.push_back(it.second);
        s += it.second;
        cum.push_back(s);
    }

    int dist = num.size();

    vector<vector<LL>> ways(k, vector<LL>(dist));

    FOR(len,0,k) {
        ways[len][0] = modpow(cnt[0], len+1, Inf);
        //cout << ways[len][0] << endl;
    }

    FOR(min,1,dist) {
        ways[0][min] = cum[min];
        FOR(len,1,k) {
            ways[len][min] = (ways[len][min-1] + cnt[min] * ways[len-1][min] % Inf) % Inf;
        }
    }

    // Sequences not ending in remainder
    s = 0;
    FOR(i,0,MIN(l/n,k)) {
        //cout << ((l/n-i)%Inf) << " * " << ways[i][dist-1] << " ways to make sequence of len " << i+1 << " without remainder" << endl;
        s = (s + ((l/n-i)%Inf)*ways[i][dist-1] % Inf) % Inf;
    }

    for(auto& it : rem) {
        int pos = lower_bound(num.begin(), num.end(), it.first) - num.begin();

        //cout << "Adding " << it.first << ": " << it.second << " at pos " << pos << endl;
        s = (s + it.second) % Inf; // 1 item sets
        FOR(i,0,MIN(l/n,k-1)) {
            //cout << "  ways[" << i << "][" << pos << "] = " << ways[i][pos] << endl;
            s = (s + it.second * ways[i][pos] % Inf) % Inf;
        }
    }

    cout << s << endl;

    return 0;
}
