#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

char s[100002] = "0";

int main() {
	int n, l;

	cin >> (s+1);
    n = atoi(s + strlen(s) - 2); // last 1-2 digits
    cout << (n%4 ? 0 : 4) << endl;

    return 0;
}
