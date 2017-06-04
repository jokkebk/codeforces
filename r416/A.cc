#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

#define M 1000000007LL

int main() {
    int a, b;

    cin >> a >> b;

    for(int n=1; n<100000; n++) {
        if(n*n > a) {
            cout << "Vladik" << endl;
            return 0;
        }
        if(n*n+n > b) {
            cout << "Valera" << endl;
            return 0;
        }
    }
}
