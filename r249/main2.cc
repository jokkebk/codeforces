#include <iostream>
#include <string.h>

using namespace std;

#define SWAP(a,b,c) { c=a; a=b; b=c; }

int main() {
	int swaps;
	char str[20], t;

	cin >> str >> swaps;

     for(int i=0; i<strlen(str) && swaps; i++) {
		int best = str[i], bestI = i;

		for(int j=i+1; j<strlen(str) && (j-i) <= swaps; j++) {
			if(str[j] > best) {
				best = str[j];
				bestI = j;
			}
		}
		for(; bestI > i; bestI--, swaps--)
			SWAP(str[bestI-1], str[bestI], t);
	}

	cout << str << endl;

	return 0;
}
