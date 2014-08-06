#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; ++i)

int n, m, k, w;
char *s;

int dynDiff(int i, int j) {
    static map<pair<int,int>,int> res;
    auto it = res.find(make_pair(i,j));

    if(it != res.end()) return it->second;

    int diff = 0;

    FOR(k,0,n*m) if(s[i*n*m + k] != s[j*n*m + k]) diff++;

    cout << "Storing " << diff << endl;

    return res[make_pair(i,j)] = diff;
}

int main() {

    cin >> n >> m >> k >> w;

    s = new char[n * m * k + 5]; // a little bit extra for \r\n\0

    FOR(y,0,n*k) {
        cin >> &s[y*m];
    }

    while(true) {
        int i, j;
        cin >> i >> j;
        if(!i || !j) break;
        cout << dynDiff(i-1, j-1) << endl;
    }

    cout << s;

    delete s;

    return 0;
}
