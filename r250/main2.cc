#include <iostream>

using namespace std;

// Memory allocation for sets of lowmin 1's, 2's, 4's etc.
int set[100000], n = 0;

int genLows(int bit, int limit) {
    int low = 1 << bit, add = 1 << (bit+1), start = n;

    for(int i = 0; i + low <= limit; i+= add)
        set[n++] = i + low;

    return n - start;
}

int main() {
    int sum, limit, i, j, need, total = 0;
    int *lows[20], items[20], left[20];

    cin >> sum >> limit;

    for(i=0; i<20; i++) {
        lows[i] = set + n; // start
        left[i] = items[i] = genLows(i, limit);
    }

    for(i=0; i<20; i++) {
        if(!(sum & (1 << i)))
            continue; // skip the bit

        for(need = (1 << i), j=i; need && j>=0; j--) {
            if(need > (left[j] << j)) { // not enough
                need -= left[j] << j; // reduce need
                left[j] = 0; // all taken
            } else {
                left[j] -= need >> j; // take some
                need = 0; // done
            }
        }

        if(need) { // not enough
            cout << -1 << endl;
            return 0;
        }
    }

    for(i=0; i<20; i++)
        total += items[i] - left[i];

    cout << total << endl;

    for(i=0; i<20; i++) {
        for(j=0; j<items[i]-left[i]; j++) {
            cout << lows[i][j];
            if(--total > 0)
                cout << " ";
        }
    }

    cout << endl;

    return 0;
}
