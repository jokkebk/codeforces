#include <iostream>
#include <string.h>

using namespace std;

int inset[51], n;

// silly join
void merge(int a, int b) {
    int i = inset[a], j = inset[b], k;

    for(k=1; k<=n; k++)
        if(inset[k] == j)
            inset[k] = i;
}

int main() {
    int m, i, a, b;
    long long danger = 1;

    cin >> n >> m;

    if(m == 0) {
        cout << 1 << endl;
        return 0;
    }

    for(i=1; i<=n; i++)
        inset[i] = i; // own set for each

    for(i=0; i<m; i++) {
        cin >> a >> b;
        if(inset[a] == inset[b])
            continue; // already mixed
        merge(a, b); // mix
        danger *= 2;
    }

    cout << danger << endl;

    return 0;
}
