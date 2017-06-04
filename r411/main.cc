#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

#define M 1000000007LL

int main() {
    int n;
    char s[5] = "aabb";

    cin >> n;

    while(n>4) cout << s, n -= 4;
    s[n] = '\0';
    cout << s << endl;
}
