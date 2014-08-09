#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

int main() {
    vector< pair<int,int> > laptops;
	int n, p, q;

	cin >> n;

    REP(n) {
        cin >> p >> q;
        laptops.push_back(make_pair(p, q));
    }

    sort(laptops.begin(), laptops.end());

    q = 0;

    for(auto it : laptops) {
        if(it.second < q) {
            cout << "Happy Alex" << endl;
            return 0;
        }
        q = it.second;
    }

    cout << "Poor Alex" << endl;

    return 0;
}
