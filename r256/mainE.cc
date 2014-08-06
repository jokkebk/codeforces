#include <iostream>
#include <map>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

map<LL,int> factors;
vector<LL> divs, ans;

void recurseDivs(LL num, map<LL,int>::iterator f) {
    if(f == factors.end()) {
        divs.push_back(num);
    } else {
       LL mul = 1;
       for(int i = 0; i <= f->second; ++i, mul *= f->first)
           recurseDivs(num * mul, next(f));
    }
}

int main() {
    LL X, k;

    cin >> X >> k;

    for(LL i = 2, orig = X; i*i <= orig && X > 1; ++i) {
        while(!(X % i)) {
            factors[i]++;
            X /= i;
        }
    }

    if(X > 1) factors[X] = 1; // max 1 factor larger than sqrt(X)

    recurseDivs(1, factors.begin());
    sort(divs.begin(), divs.end());

    vector< tuple<LL,LL,LL> > S = { make_tuple(divs.back(), 0, k) };

    do { // Have to do stack-based recursion to avoid heap overflow
        LL num = get<0>(S.back()), i = get<1>(S.back()), k = get<2>(S.back());
        S.pop_back();

        if(num == 1 || k == 0) {
            ans.push_back(num);
        } else { // num > 1 && k > 0
            if(i+1 < divs.size() && divs[i+1] <= num) // try next one?
                S.push_back(make_tuple(num, i + 1, k));

            if(!(num % divs[i])) // go deeper?
                S.push_back(make_tuple(divs[i], 0, k - 1));
        }
    } while(!S.empty() && ans.size() < 1e5);

    for(LL v : ans) cout << v << " ";

    return 0;
}
