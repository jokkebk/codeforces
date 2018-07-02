#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, n;

    cin >> a >> b >> c >> n;

    int f = n+c-a-b;
    cout << (f<=0 ? -1 : f) << endl;
}
