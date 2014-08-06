#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char str[4][128];
    int i, j, len, shortest = -1, longest = -1;

    for(i=0; i<4; i++)
        cin >> str[i];

    // Find longest
    for(i=0; i<4; i++) {
        len = 0;
        for(j=0; j<4; j++) {
            if(i != j)
                len = max(len, (int)strlen(str[j]));
        }

        if(len > 0 && strlen(str[i])-2 >= 2*(len - 2))
            longest = i;
    }

    // Find shortest
    for(i=0; i<4; i++) {
        len = 999;
        for(j=0; j<4; j++) {
            if(i != j)
                len = min(len, (int)strlen(str[j]));
        }

        if(len != 999 && 2*(strlen(str[i])-2) <= len - 2)
            shortest = i;
    }
    
    for(i=0; i<4; i++)
        str[i][1] = 0;

    if(longest != -1 && shortest == -1)
        cout << str[longest] << endl;
    else if(longest == -1 && shortest != -1)
        cout << str[shortest] << endl;
    else
        cout << "C" << endl;

    return 0;
}
