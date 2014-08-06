#include <iostream>

using namespace std;

int main() {
	int groups, capacity, buses, left, group;

    cin >> groups >> capacity;

	buses = 0;
	left = capacity;

    for(int i=0; i<groups; i++) {
		cin >> group;

		if(left >= group) { // fits
			left -= group;
		} else { // new bus
			buses++;
			left = capacity - group;
		}

		//cout << buses << " buses, plus " << left << endl;
    }

	cout << ((left == capacity) ? buses : buses + 1) << endl;

    return 0;
}
