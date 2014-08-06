#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fill(vector<int> & v, int n) {
	int val;

	while(n-- > 0) {
		cin >> val;
		v.push_back(val);
	}
}

void printv(vector<int> & v) {
	for(auto it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout << endl;
}

int main() {
	int n, m, aMul = 1, bMul = 1, diff, i, ap, bp;
	long long ops = 0;
	vector<int> a, b;
	vector<int>::iterator it;

	cin >> n >> m;

	fill(a, n);
	fill(b, m);

	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend()); // largest first

	if(n == 0 || m == 0) {
		cout << "0" << endl;
		return 0;
	}

	for(ap = bp = 0; a[ap] < b[bp]; ) {
		for(; ap+1 < a.size() && a[ap+1] == a[ap]; ap++)
            aMul++; // consolidate equals

		for(; bp+1 < b.size() && b[bp+1] == b[bp]; bp++)
            bMul++; // consolidate equals

        diff = b[bp] - a[ap];

		if(aMul <= bMul) {
            if(ap + 1 < a.size() && a[ap+1] - a[ap] < diff)
                diff = a[ap+1] - a[ap];
			a[ap] += diff;
			ops += (long long)diff * (long long)aMul;
		} else {
            if(bp + 1 < b.size() && b[bp] - b[bp+1] < diff)
                diff = b[bp] - b[bp+1];
			b[bp] -= diff;
			ops += (long long)diff * (long long)bMul;
		}
	}

	cout << ops << endl;

	return 0;
}
