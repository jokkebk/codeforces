#include <iostream>
#include <string.h>

using namespace std;

bool test(char *s, int n) {
    for(int i=0; i<n; i++)
        if(s[i+n] != '*' && s[i] != s[i+n])
            return false;

    return true;
}

int main() {
    char line[2048], letters[256];
    int i, stars, len;
    int start, n, tandem = 0;

    cin.getline(line, 1024);
    cin >> stars;
    len = strlen(line);

    for(i=len; i<len+stars; i++)
        line[i] = '*';

    line[i] = 0;
    len += stars;

    for(start = 0; start < len; start++) {
        for(n = tandem + 1; n <= (len - start) / 2; n++)
            if(test(line + start, n))
                tandem = n;
    }

    cout << 2 * tandem;

    return 0;
}
