#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

typedef long long LL;

#define M 1000000007LL

int main() {
    vector<char> v[2];
    string s[2];

    cin >> s[0] >> s[1];

    for(int i=0; i<2; i++) sort(s[i].begin(), s[i].end());

    for(int i=0; i<s[0].size() / 2; i++) v[0].push_back(s[0][i]);
    for(int i=s[1].size()/2; i<s[1].size(); i++) v[1].push_back(s[1][i]);

    int b = 0, e = s[0].size()-1, bi=0, bo=0;

    for(int i=0; i<s[0].size(); i++) s[0][i] = '?';
    for(int i=0; i<s[0].size(); i++) {
        cout << "From " << b << " to " << e << endl;
        for(int i=0; i<2; i++) { for(char c : v[i]) cout << c << " "; cout << endl; }

        if(i & 1) { // Igor
            if(v[1].back() < v[0][0]) { // all my letters are small
                s[0][e--] = v[1][bi++];
            } else { // I have at least one big letter
                s[0][b++] = v[1].back();
                v[1].pop_back();
            }
        } else { // Olya
            if(v[1].back() < v[0][0]) { // all my letters are big
                s[0][e--] = v[0].back();
                v[0].pop_back();
            } else {
                s[0][b++] = v[0][bo++];
            }
        }

        cout << "String now " << s[0] << endl;
    }
}
