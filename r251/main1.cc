#include <iostream>

using namespace std;

int main() {
	int songs, maxDuration, duration = 0, jokes = 0, len;

	cin >> songs >> maxDuration;

	for(int i=0; i<songs; i++) {
		cin >> len;

		duration += len;

		if(i + 1 < songs) {
			duration += 10;
			jokes += 2;
		}
	}

	if(duration > maxDuration)
		cout << -1;
	else
		cout << ((maxDuration - duration) / 5 + jokes);

	return 0;
}
