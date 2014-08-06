#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORD(i,a,b) for(int i=a; i>b; --i)
#define FORDE(i,a,b) for(int i=a; i>=b; --i)

int ht[300][300], tt[300][300][8], n, m, t, tp, tu, td;

#define DT(a,b) ((a) == (b) ? tp : ((a) < (b) ? tu : td))

void print(const char *s, int k) {
    cout << s << endl;
    FOR(i,0,n) {
        FOR(j,0,m) cout << setw(2) << tt[i][j][k] << " ";
        cout << endl;
    }
}

int main() {
    int i1, j1, i2, j2, bestDt = 2e9;

    cin >> n >> m >> t >> tp >> tu >> td;
    FOR(i,0,n) FOR(j,0,m) cin >> ht[i][j];

    FOR(i,0,n) {
        tt[i][0][0] = 0;
        tt[i][m-1][2] = 0;
        FOR(j,1,m) {
            tt[i][j][0] = tt[i][j-1][0] + DT(ht[i][j-1], ht[i][j]);
            tt[i][m-1-j][2] = tt[i][m-j][2] + DT(ht[i][m-j], ht[i][m-1-j]);
        }
    }

    FOR(j,0,m) {
        tt[0][j][1] = 0;
        tt[n-1][j][3] = 0;
        FOR(i,1,n) {
            tt[i][j][1] = tt[i-1][j][1] + DT(ht[i-1][j], ht[i][j]);
            tt[n-1-i][j][3] = tt[n-i][j][3] + DT(ht[n-i][j], ht[n-1-i][j]);
        }
    }

    //int dt = tt[imin][jmax][0] - tt[imin][jmin][0] +
    //    tt[imax][jmax][1] - tt[imin][jmax][1] +
    //    tt[imax][jmin][2] - tt[imax][jmax][2] +
    //    tt[imin][jmin][3] - tt[imax][jmin][3];
    FOR(i,0,n) FOR(j,0,m) { // precalc above factors
        tt[i][j][4] = tt[i][j][3] - tt[i][j][0]; // imin, jmin
        tt[i][j][5] = tt[i][j][0] - tt[i][j][1]; // imin, jmax
        tt[i][j][6] = tt[i][j][2] - tt[i][j][3]; // imax, jmin
        tt[i][j][7] = tt[i][j][1] - tt[i][j][2]; // imax, jmin
    }

    FOR(imin,0,n) FOR(jmin,0,m) {
        int d1 = tt[imin][jmin][4] - t;
        FOR(imax,imin+2,n) {
            int d2 = d1 + tt[imax][jmin][6];
            FOR(jmax,jmin+2,m) {
                int dt = d2 +
                    tt[imin][jmax][5] +
                    tt[imax][jmax][7];
                if(abs(dt) < bestDt)
                    i1 = imin, j1 = jmin, i2 = imax, j2 = jmax, bestDt = abs(dt);
            }
        }
    }

    cout << i1+1 << " " << j1+1 << " " << i2+1 << " " << j2+1 << endl;

    return 0;
}
