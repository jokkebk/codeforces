#include <iostream>
#include <map>

using namespace std;

int main() {
    int rows, cols, tubes, x, y, tube, len;

    cin >> rows >> cols >> tubes;

    tube = len = 0;
    x = y = 0;

    while(y<cols) {
        if(len == 0) { // first item of tube
            if(tube + 1 < tubes) // still tubes to go
                cout << 2;
            else
                cout << (rows * cols - (tubes-1) * 2);
        }

        cout << " " << x+1 << " " << y+1;

        // zigzag
        if((y & 1) == 0) {
            x++;
            if(x >= rows) {
                x = rows - 1;
                y++;
            }
        } else {
            x--;
            if(x < 0) {
                x = 0;
                y++;
            }
        }

        if(++len == 2 && tube + 1 < tubes) {
            cout << endl; // end this tube
            tube++; // begin a new
            len = 0;
        }
    }

    cout << endl; // end this tube

    return 0;
}
