#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)

typedef long long LL;

int main() {
    int n, dots = 0, num = 0, last = 0;
    string s;

    cin >> n >> s;

    for(char ch : s) {
        if(ch == '.') {
            dots++;
        } else  {
            if(ch == 'R') 
               num += dots;
            else if(last && dots%2)
               num++;
            last = ch, dots = 0;
        }
    }

    if(!last || last == 'L') num += dots;

    cout << num;
}
