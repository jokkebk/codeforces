#include <iostream>
#include <set>

using namespace std;

int main() {
    vector<set<char>> chs('z'-'a'+1);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(char ch : s) {
            cout << ch << endl;
        }
    }
    return 0;
}
