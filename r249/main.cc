#include <iostream>

using namespace std;

//#define REP(n) for(int _i=n; _i>0; --_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

int **black, **cmin, **cmax, **rmin, **rmax, **smin, **smax, **bmin, **bmax;
int n, m;

int **reserve2d(int n, int m) {
    int **b = new int*[n];

    FOR(i,0,n) {
        b[i] = new int[m];
        FOR(j,0,m)
            b[i][j] = 0;
    }

    return b;
}

void print(int **b) {
    FORE(i,1,n) {
        FORE(j,1,m)
            cout << b[i][j] << " ";
        cout << endl;
    }
}

void scanminmax(int di, int dj, int **mini, int **maxi) {
}

int main() {
    char str[512];
    int num = 0;

    cin >> n >> m;

    black = reserve2d(n+1, m+1);
    FOR(i,0,n) {
        cin >> str;
        FOR(j,0,m)
            black[i][j] = (str[j] == '1') ? 1 : 0;
    }

    cmin = reserve2d(n+1, m+1); // column min and max
    cmax = reserve2d(n+1, m+1);
    scanminmax(1, 0, cmin, cmax);
    cout << "cmin" << endl; print(cmin);
    cout << "cmax" << endl; print(cmax);

    rmin = reserve2d(n+1, m+1); // row min and max
    rmax = reserve2d(n+1, m+1);
    scanminmax(0, 1, rmin, rmax);
    cout << "rmin" << endl; print(rmin);
    cout << "rmax" << endl; print(rmax);

    smin = reserve2d(n+1, m+1); // diagonal '/' min and max ("slash")
    smax = reserve2d(n+1, m+1)
    scanminmax(-1, 1, smin, smax);
    cout << "smin" << endl; print(smin);
    cout << "smax" << endl; print(smax);

    bmin = reserve2d(n+1, m+1) // diagonal '\' min and max ("backslash")
    bmax = reserve2d(n+1, m+1)
    scanminmax(1, 1, bmin, bmax);
    cout << "bmin" << endl; print(bmin);
    cout << "bmax" << endl; print(bmax);

    return 0;
}
