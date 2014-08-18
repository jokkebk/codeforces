#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)

int n, a[200000], num = 0;

int ari(int pos) { // find arithmetic progression from pos and return end+1
    int i, ival, j, jval, k, kval, add;

    for(i=pos; i<n && a[i] == -1; ++i) {}
    if(i == n) return n;
    ival = a[i];

    for(j=i+1; j<n && a[j] == -1; ++j) {}
    if(j == n) return n;
    jval = a[j];

    cout << "a[" << i << "] = " << ival << " and a[" << j << "] = " << jval << endl;

    return j+1;
}

int main() {
    cin >> n;
    FOR(i,0,n) cin >> a[i];

    for(int pos=0; pos<n; num++)
        pos = ari(pos);

    cout << num << endl;

    return 0;
}
