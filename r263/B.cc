#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)

typedef long long LL;

char s[100005];
LL n, k, ways = 0;

int main() {
    map<char,LL> letters;
    vector<LL> nums;

    cin >> n >> k >> s;

    FOR(i,0,n) letters[s[i]]++;

    for(auto p : letters) {
        nums.push_back(p.second);
        //cout << p.second << " * " << p.first << endl;
    }

    sort(nums.begin(), nums.end());

    while(k > 0 && !nums.empty()) {
        LL num = min(k, nums.back()); nums.pop_back();
        ways += num * num;
        k -= num;

        //cout << num << endl;
    }

    cout << ways;

    return 0;
}
