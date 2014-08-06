#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, p, v, i;
    vector<int> odd, even;

    cin >> n >> k >> p;

    for(i=0; i<n; i++) {
        cin >> v;

        if(v & 1)
            odd.push_back(v);
        else
            even.push_back(v);
    }

    if(odd.size() < (k-p) || (odd.size() - (k-p)) % 2 != 0 ||
       even.size() + (odd.size() - (k-p)) / 2 < p) {
        cout << "NO";
        return 0;
    }

    cout << "YES" << endl;

    for(i=(p ? 0 : 1); i<k-p; i++) {
        cout << "1 " << odd.back() << endl;
        odd.pop_back();
    }

    for(i=1; i<p; i++) {
        if(even.empty()) {
            cout << "2 " << odd.back();
            odd.pop_back();
            cout << " " << odd.back() << endl;
            odd.pop_back();
        } else {
            cout << "1 " << even.back() << endl;
            even.pop_back();
        }
    }

    odd.reserve(odd.size() + even.size());
    odd.insert(odd.end(), even.begin(), even.end()); // merge

    cout << odd.size();

    for(auto it = odd.begin(); it < odd.end(); it++)
        cout << " " << *it;

    cout << endl;

    return 0;
}
