#include <iostream>
#include <map>

using namespace std;

int analyze(int *p, int *pGroup, int *gSize, int n) {
    int groups = 0, i, count;

    for(i = 0; i < n; i++)
        pGroup[i] = -1;

    // Number cyclic groups within permutation
    for(i = count = 0; count < n;) {
        pGroup[i] = groups;
        gSize[groups]++;
        count++;
        i = p[i] - 1; // next item in cycle

        if(pGroup[i] == groups) { // cycle complete
            groups++;
            for(i=0; i<n; i++)
                if(pGroup[i] == -1)
                    break; // continue from here
        }
    }

    return groups;
}

int main() {
    int n, p[3000], m, i;
    int pGroup[3000], gSize[3000], groups;
    int minSwaps;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> p[i];

    cin >> m;

    groups = analyze(p, pGroup, gSize, n);

    for(i = 0; i < n; i++)
        cout << i << ": " << p[i] << " in group " << pGroup[i] << " (" << gSize[pGroup[i]] << " items)" << endl;

    minSwaps = 0;
    for(i = 0; i < groups; i++)
        minSwaps += gSize[i] - 1;

    cout << minSwaps << " swaps needed for identity" << endl;

    if(minSwaps >= m) { // go towards identity
        cout << "Go towards identity" << endl;
        cout << (minSwaps - m);
    } else { // go away from identity
        cout << "Go away from identity" << endl;
        cout << (m - minSwaps);
    }


    return 0;
}
