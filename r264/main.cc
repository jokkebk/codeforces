#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

int after[1024][1024];

int main() {
	int s[5][1000], n, k, len[1000];

    cin >> n >> k;

	FOR(i,0,k) FOR(j,0,n) cin >> s[i][j];
	
	FOR(i,0,n) memset(after[i], 0, 1024*sizeof(int));
	memset(len, 0, 1000*sizeof(int));

	FOR(i,0,k) {
		FOR(j,0,n) FOR(m,j+1,n) after[s[i][j]-1][s[i][m]-1]++;
	}

	FOR(i,0,n) {
		cout << i+1 << ": ";
		FOR(j,0,n)
			if(after[i][j] == k)
				cout << j+1 << " ";
		cout << endl;
	}

    return 0;
}
