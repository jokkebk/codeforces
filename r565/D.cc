#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

typedef long long LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<bool> prime(2750132, true);

    for(int i=2; i<1659; i++) {
        if(!prime[i]) continue;
        for(int j=2*i; j<prime.size(); j+=i)
            prime[j] = false;
    }

    vector<int> pr(200001);
    int pos = 0;

    for(int i=1; i<prime.size(); i++)
        if(prime[i]) pr[pos++] = i;

    int n;

    cin >> n;
    vector<int> b(n*2);
    for(int i=0; i<n*2; i++)
        cin >> b[i];
    sort(b.rbegin(), b.rend());

    vector<int> p, a;
    map<int,int> skip;

    //cout << "Go through ";
    //for(int v : b) cout << v << " "; cout << endl;
    for(int v : b) {
        if(skip[v]) {
            skip[v]--;
            continue;
        }
        bool prime = true;
        if(v <= 200000) {
            for(int d = 2; d < min(448, v); d++) {
                if(v%d) continue;
                a.push_back(v); // composite, and not biggest divisor
                skip[v/d]++; // skip the biggest divisor later on
                prime = false;
                break;
            }
        }
        if(prime) p.push_back(v);
    }

    //for(int v : a) cout << v << " "; cout << endl;
    sort(p.begin(), p.end());
    skip.clear();
    //cout << "Iterate ";
    //for(int v : p) cout << v << " "; cout << endl;
    for(int v : p) {
        if(skip[v]) {
            //cout << "Hoy skipping " << v << endl;
            skip[v]--;
            continue;
        }
        a.push_back(v);
        //cout << "Add " << v << " and skip " << pr[v] << endl;
        skip[pr[v]]++;
    }

    for(int v : a) cout << v << " "; cout << endl;
}
