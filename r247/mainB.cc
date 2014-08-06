#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

int g[5][5];

int happiness(int *pers) {
    int h = 0;

    FOR(i, 0, 4)
        for(int j=i; j+1 < 5; j+=2)
            h += g[pers[j]][pers[j+1]] + g[pers[j+1]][pers[j]];

    return h;
}

int main() {
    int pers[5] = {0, 1, 2, 3, 4}, h = 0;

    FOR(i, 0, 5)
        FOR(j, 0, 5)
            cin >> g[i][j];

    do {
        h = max(h, happiness(pers));
        //FOR(i, 0, 5)
            //cout << pers[i] << " ";
        //cout << "happiness: " <<  << endl;
    } while(next_permutation(pers,pers+5));

    cout << h << endl;

    return 0;
}
