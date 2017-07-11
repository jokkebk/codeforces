#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

typedef long long LL;

#define M 1000000007LL

int main() {
    double n, h;

    cin >> n >> h;

    for(double i=1; i<n; i++)
        cout << setprecision(8) << (h * sqrt(i/n)) << endl;
}
