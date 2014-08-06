#include <iostream>

using namespace std;

#define N 100000

int prevPrime[N+1], num[N+1], where[N+1];
int s[5*N][2], ss = 0;

void swap(int i, int j) {
    int a = num[i], b = num[j];

    num[i] = b;
    num[j] = a;
    where[a] = j;
    where[b] = i;

    s[ss][0] = j;
    s[ss][1] = i;
    ss++;
}

void move(int a, int b) {
    int offset = a - b;

    if(a == b) return; // nothing to do

    if(prevPrime[offset+1] == offset +1) {
        swap(a, b);
    } else {
        int m = prevPrime[offset]; // previous prime
        swap(a, a - m + 1);
        move(a - m + 1, b);
    }
}

int main() {
    int n, i, j;

    for(i=1; i<=N; i++)
        prevPrime[i] = i;

    for(i=2; i<=316; i++) {
        if(prevPrime[i] != i) continue;
        for(j=i*2; j<=N; j+=i)
            prevPrime[j] = i;
    }

    j=3;
    for(i=j+1; i<=N; i++) {
        if(prevPrime[i] == i) { // prime
            j = i;
        } else {
            prevPrime[i] = j;
        }
    }

    cin >> n;

    for(i=1; i<=n; i++) {
        cin >> num[i];
        where[num[i]] = i;
    }

    for(i=1; i<=n; i++)
        move(where[i], i);

    cout << ss << endl;
    for(i=0; i<ss; i++)
        cout << s[i][0] << " " << s[i][1] << endl;
    return 0;
}
