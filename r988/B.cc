#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    // Speed up input/output operations
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    cin.ignore(); // Discard the newline character after T

    while (T--) {
        string s;

        // Discard the first line (equivalent to input() in Python)
        getline(cin, s);

        // Read the line containing the integers
        getline(cin, s);
        istringstream iss(s);
        int num;
        vector<int> a;
        map<int, int> C;

        // Build the list 'a' and the counter 'C'
        while (iss >> num) {
            a.push_back(num);
            C[num]++;
        }

        int d = a.size() - 2;
        bool found = false;

        // Loop from 1 to 10^7 as in the original Python code
        for (int n = 1; n < 10000000; ++n) {
            if (n * n == d && C[n] > 1) {
                cout << n << " " << n << endl;
                found = true;
                break;
            }
            if (d % n == 0) {
                int m = d / n;
                if (C[n] > 0 && C[m] > 0) {
                    cout << n << " " << m << endl;
                    found = true;
                    break;
                }
            }
            // Optional early termination if n exceeds d
            if (n > d) break;
        }

        // If no pair found, output as per requirements (e.g., "-1 -1")
        if (!found) {
            cout << "-1 -1" << endl;
        }
    }

    return 0;
}