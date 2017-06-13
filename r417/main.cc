#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

#define M 1000000007LL

int main() {
    int n, S, best = 0;

    cin >> n >> S;

    vector<int> a(n);

    for(int i=0; i<n; i++) cin >> a[i];
    
    int k = 0;

    for(int add = 1024; add; add /= 2) {
        if(k + add > n) continue;
        else k += add;

        vector<int> c;

        for(int i=0; i<n && i*k <= S; i++) c.push_back(-(a[i] + (i+1) * k));

        make_heap(c.begin(), c.end());

        int sum = 0;

        for(int i=0; i<k && sum<=S; i++) {
            pop_heap(c.begin(), c.end());
            sum -= c.back();
            c.pop_back();
        }

        if(sum > S) k -= add; else best = sum;
    }

    cout << k << " " << best << endl;
}
