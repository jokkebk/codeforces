#include <iostream>

using namespace std;

typedef union {
    struct State { unsigned int low8 : 8, zeros : 8, ones : 6, rest : 10; } st;
    uint32_t i;
} Index;

char *bin2str(unsigned int n) { // fake utility function
    static char str[36] = "00001111 00001111 00001111 00001111";
    char *s = str+34;

    for(unsigned int i=0; i<32; ++i) {
        *s-- = '0' + ((n>>i) & 1);
        if((i & 7) == 7) s--; // "add" space
    }
    return str;
}

int main() {
    int zeros, ones, low8;
    Index t = {0};

    cout << sizeof(Index) << endl;

    do {
        cin >> zeros >> ones >> hex >> low8 >> dec;
        t.st.zeros = zeros;
        t.st.ones = ones;
        t.st.low8 = low8;
        cout << bin2str(t.i) << endl;
    } while(t.i);

    return 0;
}
