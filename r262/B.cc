#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

LL s(LL i) {
    LL sum = 0;

    while(i > 0) {
        sum += i%10;
        i /= 10;
    }

    return sum;
}

int main() {
    LL a, b, c, x;
    vector<LL> ans;

    cin >> a >> b >> c;

    FORE(i,1,81) {
        x = 1;
        FORE(j,1,a) x *= i;
        x = b * x + c;
        if(x < 1e9 && s(x) == i) ans.push_back(x);
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;

    for(LL i : ans) cout << i << " ";

    return 0;
}
