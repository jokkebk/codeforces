#include <iostream>
#include <string.h>

using namespace std;

int main() {
    int sellers, money, deals = 0, n, i, price;
    bool seller[100], done;

    cin >> sellers >> money;

    for(i=0; i<sellers; i++) {
        seller[i] = false;
        for(cin >> n; n > 0; n--) {
            cin >> price;
            if(money > price && !seller[i]) {
                deals++;
                seller[i] = true;
            }
        }
    }

    cout << deals << endl;

    for(i=0; i<sellers; i++) {
        if(seller[i]) {
            cout << (i+1);
            if(--deals > 0)
                cout << " ";
        }
    }

    cout << endl;

    return 0;
}
