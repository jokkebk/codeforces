#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

#define M 1000000007LL

int main() {
    int n, m, top = 999;
    string s;

    cin >> n >> m;

    vector<int> minR(n), minL(n);

    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=1; j<=m; j++) {
            if(s[j] == '0') continue;
            else top = min(top, i); // top floor with lights
            minL[i] = max(j, minL[i]); // minimum walk from left
            minR[i] = max(m+1-j, minR[i]); // minimum walk from right
        }
    }

    if(top == 999) {
        cout << 0 << endl;
        return 0;
    }

    int bestL = -1, bestR = 999;

    for(int i=n-1; i>top; i--) {
        int R = bestR, L = bestL;
        bestL = min(L + 1 + 2 * minL[i], // up from below, to last light and back
                R + 1 + m+1); // up from right, and accross the floor
        bestR = min(R + 1 + 2 * minR[i], // up from below, to last light and back
                L + 1 + m+1); // up from right, and accross the floor
    }
    
    cout << min(bestL + 1 + minL[top], bestR + 1 + minR[top]) << endl;
}
