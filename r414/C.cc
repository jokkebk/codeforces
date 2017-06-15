#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s0, s1, r;

    cin >> s0 >> s1;
    sort(s1.begin(), s1.end());
    sort(s0.begin(), s0.end());
    r = s0;
    s0.resize((r.size()+1)/2);
    s1 = s1.substr((r.size()+1)/2);

    int b1=0, e1=s1.size()-1,
        b0=0, e0=s0.size()-1,
        br=0, er=r.size()-1;

    for(int i=0; i<r.size(); i++) {
        if(i&1) { // Igor
            if(s1[e1] <= s0[b0]) // all small letters for Igor
                r[er--] = s1[b1++];
            else // at least some is bigger than Oleg
                r[br++] = s1[e1--];
        } else { // Oleg
            if(s1[e1] <= s0[b0]) // all small letters for Igor
                r[er--] = s0[e0--];
            else // at least some is bigger than Oleg
                r[br++] = s0[b0++];
        }
    }
    cout << r << endl;
}
