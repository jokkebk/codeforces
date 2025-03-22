#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t, n;
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;

    while (t--) {
        cin >> n;
        
        vector<int> a(n);
        for (int &x : a) cin >> x;
        
        // Count frequencies
        unordered_map<int, int> f;
        for (int x : a) f[x]++;
        
        // Find positions of numbers that appear multiple times
        vector<int> p = {-1};
        for (int i = 0; i < n; ++i)
            if (f[a[i]] > 1) p.push_back(i);
        p.push_back(n);
        
        // Find max gap
        int max_len = 0, left = 0, right = 0;
        for (size_t i = 0; i < p.size() - 1; ++i) {
            if (p[i+1] - p[i] > max_len) {
                max_len = p[i+1] - p[i];
                left = p[i]; right = p[i+1];
            }
        }
        
        if (max_len <= 1) cout << "0\n";
        else cout << (left + 2) << " " << right << "\n";
    }
    
    return 0;
}