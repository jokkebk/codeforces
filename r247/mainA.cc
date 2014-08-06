#include <iostream>

using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

int main() {
    int cal[4], cals = 0;
    char str[100001];

    FOR(i, 0, 4)
        cin >> cal[i];

    cin >> str;

    for(int i=0; str[i]; i++)
        cals += cal[str[i]-'1'];

    cout << cals << endl;

    return 0;
}
