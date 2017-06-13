#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

#define M 1000000007LL

bool inc(vector<int> & l) {
    int p = 0;
    for(int v : l) if(v < p) return false; else p = v;
    return true;
}

int main() {
    int n, k;

    cin >> n >> k;

    vector<int> a(n), b(k);

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<k; i++) cin >> b[i];
    
    if(k > 2) {
        cout << "YES" << endl;
    } else if(k == 2) {
        int s, e;
        for(int i=0; i<n; i++) if(!a[i]) e = i;
        for(int i=n-1; i>=0; i--) if(!a[i]) s = i;

        a[s] = b[0];
        a[e] = b[1];
        
        //for(int i : a) cout << i << " "; cout << endl;
        if(inc(a)) {
            a[s] = b[1];
            a[e] = b[0];
        //for(int i : a) cout << i << " "; cout << endl;
            if(inc(a))
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        } else cout << "YES" << endl;
    } else {
        for(int i=0; i<n; i++) if(!a[i]) a[i] = b[0];
        if(inc(a))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}
