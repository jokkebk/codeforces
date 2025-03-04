#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // Disable synchronization with C-style I/O
    cin.tie(nullptr);            // Untie cin from cout for faster input

    int t;
    cin >> t;

    while (t--) {
        int n, m, L;
        cin >> n >> m >> L;

        vector<pair<int, int>> I(n); // To store "l r" pairs
        for (auto& [l, r] : I) cin >> l >> r;

        vector<pair<int, int>> P(m); // To store "x p" pairs
        for (auto& [x, p] : P) cin >> x >> p;

        sort(P.begin(), P.end()); // Sort P based on x to process in order

        priority_queue<int> heap; // Max heap (default is max in C++)
        int j = 1, c = 0;         // Initial jumping power and consumed powerups
        size_t idx = 0;           // Index to iterate over P

        for (auto [l, r] : I) {
            // Add powerups at positions before l to the heap
            while (idx < P.size() && P[idx].first < l) {
                heap.push(P[idx].second);
                idx++;
            }

            // Increase the jumping power until we can reach r
            while (j < r - l + 2) {
                if (heap.empty()) {
                    j = -1;
                    break; // Abort
                }
                j += heap.top();
                heap.pop();
                c++;
            }

            if (j == -1) break; // Abort if jumping power is insufficient
        }

        cout << (j >= 0 ? c : -1) << '\n';
    }

    return 0;
}