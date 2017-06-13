#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

#define M 1000000007LL

int main() {
    int d = 0;
    string s;

    cin >> s;

    for(int i=0; i<s.length()/2; i++)
        if(s[i] != s[s.length()-1-i]) d++;

    if(d <= 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}
