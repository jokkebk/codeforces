#include <iostream>

using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

int main() {
    int odd=0, even=0, n, w;

    cin >> n;

    FOR(i,0,n) {
        cin >> w;
        if(w == 100)
            odd++;
        else
            even++;
    }

    if(odd & 1) // impossible
        cout << "NO" << endl;
    else if(even % 2 == 0) // both even
        cout << "YES" << endl;
    else // need at least 2 odd to balance
        cout << (odd ? "YES" : "NO") << endl;

    return 0;
}
