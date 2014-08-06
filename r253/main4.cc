#include <iostream>
#include <string.h>

using namespace std;

int main() {
    // we number cards from 0-24 and info is a bitmask of possible cards
    double p[100];
    int ps, i, bestI = -1;
    double bestP = 0, lastBest, comb;

    cin >> ps;

    for(i=0; i<ps; i++) {
        cin >> p[i];
        //cout << p[i] << endl;

        if(p[i] > bestP) {
            bestP = p[i];
            bestI = i;
        }
    }

    p[bestI] = -1; // guarantee not reselected

    for(int added = 1; added < ps; added++) {
        lastBest = bestP; // best of last round

        for(i=0; i<ps; i++) {
            if(p[i] < 0) continue; // skip this

            comb = (1 - p[i]) * lastBest + p[i] * (1-lastBest);
            if(comb > bestP) {
                bestP = comb;
                bestI = i;
            }
        }

        if(bestP > lastBest) {
            p[bestI] = -1; // guarantee not reselected
        } else break; // no improvement by adding
    }

    cout << bestP;

    return 0;
}
