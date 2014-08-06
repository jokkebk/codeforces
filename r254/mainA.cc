#include <iostream>
#include <string.h>

using namespace std;

int main() {
    int n, m, i, j;
    char board[100][101];

    cin >> n >> m;

    for(i=0; i<n; i++)
        cin >> board[i];

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if(board[i][j] == '.')
                board[i][j] = ((i+j)&1) ? 'B' : 'W';

    for(i=0; i<n; i++)
        cout << board[i] << endl;

    return 0;
}
