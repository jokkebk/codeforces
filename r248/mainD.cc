#include <iostream>

using namespace std;

#define REP(n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

int **b[5], **on, **cmin, **cmax, **rmin, **rmax;
int n, m, q;

void doRow(int i, int a, int b) {
    int mini = 0, maxi = 0;

    FORE(k,0,b-a) {
        if(on[i][a+k]) {
            if(!mini) mini = a + k;
        } else if(mini) mini = 0;

        if(on[i][b-k]) {
            if(!maxi) maxi = b - k;
        } else if(maxi) maxi = 0;

        rmin[i][a+k] = mini;
        rmax[i][b-k] = maxi;
    }
}

void doCol(int i, int a, int b) {
    int mini = 0, maxi = 0;

    FORE(k,0,b-a) {
        if(on[a+k][i]) {
            if(!mini) mini = a + k;
        } else if(mini) mini = 0;

        if(on[b-k][i]) {
            if(!maxi) maxi = b - k;
        } else if(maxi) maxi = 0;

        cmin[a+k][i] = mini;
        cmax[b-k][i] = maxi;
    }
}

int scan(int i, int j, int di, int dj) {
    int **mini, **maxi, best = 0, a = 0, b = 9999, c = 0;

    if(!on[i][j]) return 0;

    if(dj) { // going along row
        mini = cmin;
        maxi = cmax;
        c = (dj < 0) ? j - rmin[i][j] : rmax[i][j] - j;
    } else { // going along column
        mini = rmin;
        maxi = rmax;
        c = (di < 0) ? i - cmin[i][j] : cmax[i][j] - i;
    }

    FORE(k,0,c) {
        a = max(a, mini[i][j]);
        b = min(b, maxi[i][j]);
        best = max(best, (b-a+1) * (k+1));
        i += di;
        j += dj;
    }

    return best;
}

int **reserve2d(int n, int m) {
    int **b = new int*[n];

    FOR(i,0,n) {
        b[i] = new int[m];
        FOR(j,0,m)
            b[i][j] = 0;
    }

    return b;
}

int main() {
    int t, x, y, best;

    cin >> n >> m >> q;

    on = reserve2d(n+1, m+1);
    cmin = reserve2d(n+1, m+1);
    cmax = reserve2d(n+1, m+1);
    rmin = reserve2d(n+1, m+1);
    rmax = reserve2d(n+1, m+1);

    FORE(i,1,n)
        FORE(j,1,m)
            cin >> on[i][j];

    FORE(i,1,n)
        doRow(i, 1, m);

    FORE(i,1,m)
        doCol(i, 1, n);

    REP(q) {
        cin >> t >> x >> y;
        if(t == 1) {
            on[x][y] = !on[x][y];
            doRow(x, 1, m);
            doCol(y, 1, n);
        } else {
            cout << max( // 4-way maximum
                   max(scan(x, y, 1, 0), scan(x, y, -1, 0)),
                   max(scan(x, y, 0, 1), scan(x, y, 0, -1))) << endl;
        }
    }

    return 0;
}
