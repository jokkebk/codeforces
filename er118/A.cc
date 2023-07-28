#include <iostream>

using namespace std;

int main() {
    auto p = [](int x, int y) { cout << (x==y ? '=' : (x<y?'<':'>')) << endl; };
    int t, a, x, b, y;
    cin >> t;
    while(t--) {
        cin >> a >> x >> b >> y;
        for(; a < 1000000; x--) a *= 10;
        for(; b < 1000000; y--) b *= 10;
        if(x==y) p(a, b); else p(x, y);
    }
}
