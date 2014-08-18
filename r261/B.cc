#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

int main() {
	int n, b, minB = 1e9+1, minC = 1, maxB = 0, maxC = 1;

	cin >> n;

	REP(n) {
		cin >> b;

		if(b < minB) minB = b, minC = 1;
		else if(b == minB) minC++;

		if(b > maxB) maxB = b, maxC = 1;
		else if(b == maxB) maxC++;
	}

	if(minB != maxB)
		cout << maxB - minB << " " << (LL)maxC * minC;
	else
		cout << "0 " << (LL)minC * (minC-1) / 2;

	return 0;
}
