#include <iostream>

using namespace std;

int main() {
    char line[2048], letters[256];
    int i, count = 0;

    cin.getline(line, 1024);

    for(i=0; i<256; i++)
        letters[i] = 0;

    for(i=0; i<1024 && line[i]; i++)
        letters[line[i]]=1;

    for(i='a'; i<='z'; i++)
        if(letters[i])
            count++;

    cout << count;

    return 0;
}
