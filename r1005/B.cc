#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        int n;
        std::cin >> n;
        
        std::vector<int> l(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> l[i];
        }
        
        // Count occurrences (equivalent to Counter in Python)
        std::unordered_map<int, int> c;
        for (int num : l) {
            c[num]++;
        }
        
        // Indices of numbers with multiple occurrences
        std::vector<int> p;
        for (int i = 0; i < n; ++i) {
            if (c[l[i]] > 1) {
                p.push_back(i);
            }
        }
        
        // Find the longest range
        int max_range = 0;
        int left = -1;
        int right = -1;
        
        p.insert(p.begin(), -1);  // Add dummy start
        p.push_back(n);  // Add dummy end
        
        for (size_t i = 0; i < p.size() - 1; ++i) {
            int range_length = p[i+1] - p[i];
            if (range_length > max_range) {
                max_range = range_length;
                left = p[i];
                right = p[i+1];
            }
        }
        
        if (right - left <= 1) {
            std::cout << "0\n";
        } else {
            std::cout << (left + 2) << " " << right << "\n";
        }
    }
    
    return 0;
}