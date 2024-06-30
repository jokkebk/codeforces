#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Calculate 30 first Fibonacci numbers to a list
    vector<int> fib;
    fib.push_back(0);
    fib.push_back(1);
    for (int i = 0; i < 30; ++i) {
        fib.push_back(fib[i] + fib[i + 1]);
    }

    int t;
    cin >> t; // Read the number of test cases

    while (t--) {
        int n, k;
        cin >> n >> k; // Read n and k for each test case

        if (n == 0) {
            cout << 1 << endl;
        } else if (k > 30) {
            cout << 0 << endl;
        } else {
            int a = fib[k - 2];
            int b = fib[k - 1];
            int count = 0;

            for (int i = 0; i <= n / (a + b); ++i) {
                if ((n - a * i) % b == 0) {
                    int j = (n - a * i) / b;
                    count = (j - i) / (a + b) + 1;
                    break;
                }
            }

            cout << count << endl;
        }
    }

    return 0;
}