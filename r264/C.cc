#include <iostream>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)

typedef long long LL;

LL n, b[2000][2000], d1[2000][2000], d2[2000][2000];

#define D(i,j) (D1(i,j) + D2(i,j) - b[i][j])
#define N(i) (n-1-(i))
#define D1(i,j) (((j)+N(i)) < n  ? d1[n-1][(j)+N(i)] : d1[(i)+N(j)][n-1])
#define D2(i,j) (((j)-N(i)) >= 0 ? d2[n-1][(j)-N(i)] : d2[(i)+(j)][0])

int main() {
	LL best[2] = {-1, -1}, x[2], y[2];

    cin >> n;

	FOR(i,0,n) FOR(j,0,n) {
		scanf("%d", &b[i][j]);
		d1[i][j] = d2[i][j] = b[i][j];
		if(!i) continue;
		if(j) d1[i][j] += d1[i-1][j-1];
		if(j+1 < n) d2[i][j] += d2[i-1][j+1];
	}

	FOR(i,0,n) FOR(j,0,n) {
		LL sum = D(i,j), idx = (i+j) & 1;

		if(best[idx] < sum) {
			x[idx] = i+1, y[idx] = j+1;
			best[idx] = sum;
		}
	}

	cout << best[0] + best[1] << endl;
	cout << x[0] << " " << y[0] << " " << x[1] << " " << y[1] << endl;

    return 0;
}
