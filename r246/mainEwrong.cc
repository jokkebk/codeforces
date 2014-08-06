#include <iostream>

using namespace std;

char tiles[100][101];

void tile(int x, int y, int w, int h, char top, char left) {
    int s = min(w, h), c = 'A';

    if(!w || !h) return; // we're done here

    //cout << "Tiling from (" << x << ", " << y << "), "
    //    << w << " x " << h << " colors " << top << " & " << left << endl;

    if(min(top, left) == 'A') // change color if necessary
        c = max(top, left) == 'B' ? 'C' : 'B';

    if(w > h) { // wider
        if(c == 'C') { // use smaller tiles first
            tile(x, y, w-s, h, top, left);
            x += w-s;
            c = left;
        } else {
            if(left == 'A' && top == 'C') {
                // do vertical BCBCBC
                for(int i=0; i<h; i++)
                    tiles[y+i][x] = (i&1) ? 'C' : 'B';
                x++; w--; // advance & decrease width
                c = 'A'; // we can now use this
            }
            tile(x+s, y, w-s, h, top, c);
        }
    } else if(w < h) { // higher
        if(c == 'C') { // use smaller tiles first
            tile(x, y, w, h-s, top, left);
            y += h-s;
            c = top;
        } else {
            tile(x, y+s, w, h-s, c, left);
        }
    }

    for(int i=0; i<s; i++)
        for(int j=0; j<s; j++)
            tiles[y+i][x+j] = c;

}

int main() {
    int n, m;

    cin >> n >> m;

    tile(0, 0, m, n, 'C', 'C');

    for(int i=0; i<n; i++) {
        tiles[i][m] = 0;
        cout << tiles[i] << endl;
    }

    return 0;
}
