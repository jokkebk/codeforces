#include <iostream>

using namespace std;

#define REP(n) for(int _i=n; _i>0; --_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

char **cardio;

int main() {
    int n, a, sum = 0, x = 0, y, top, bottom;
    bool up = true; // direction

    cin >> n;

    y = top = bottom = 1001;
    cardio = new char*[2002];
    FOR(i,0,2002) {
        cardio[i] = new char[1001];
        FOR(j,0,1001)
            cardio[i][j] = ' ';
    }

    REP(n) {
        cin >> a;

        //cout << "From (" << x << ", " << y << ")" << endl;
        if(up) {
            FOR(i,0,a)
                cardio[y--][x++] = '/';
            top = min(top, ++y);
        } else {
            FOR(i,0,a)
                cardio[y++][x++] = '\\';
            bottom = max(bottom, --y);
        }
        //cout << "..to (" << x << ", " << y << ")" << endl;

        up = !up;
    }

    FORE(i,top,bottom) {
        cardio[i][x] = 0; // terminate
        cout << cardio[i] << endl;
    }

    return 0;
}
