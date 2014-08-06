#include <iostream>

#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

using namespace std;

char tiles[128][128]; // 1..100 x 1..100 max
int w, h;

int minC(int x, int y) {
    static int fc[9] = {1, 2, 1, 3, 1, 2, 1, 4};
    int free = (1 << tiles[y-1][x])
        | (1 << tiles[y][x-1])
        | (1 << tiles[y][x+1]);
    return fc[(free>>1)&7];
}

void fill(int x, int y) {
    int c = minC(x,y), s;

    for(s=1; x+s <= w && y+s <= h; s++)
        if(minC(x+s, y) < c || tiles[y][x+s] || tiles[y-1][x+s] == c)
            break;

    FOR(j, y, y+s)
        FOR(i, x, x+s)
            tiles[j][i] = c;
}

int main() {
    cin >> h >> w;

    FORE(y, 0, h+1)
        FORE(x, 0, w+1)
            tiles[y][x] = 0;

    FORE(y, 1, h)
        FORE(x, 1, w)
            if(!tiles[y][x])
                fill(x, y); // recursive, greedy lexographic fill

    FORE(y, 1, h) {
        FORE(x, 1, w)
            cout << (char)(tiles[y][x] + 'A' - 1);
        cout << endl;
    }

    return 0;
}
