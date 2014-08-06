#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define REP(n) for(int _i=n; _i>0; --_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

// A number viewed as low byte and n consecutive ones/zeroes before the other
typedef union {
    struct State { unsigned int low8 : 8, n : 8, ones : 1; } st;
    uint32_t i; // alternate access
} Index;

// O(1) helper to access current and previous iteration round probabilities
class Prob {
    double p, prev;
    int curRound;
  public:
    Prob() : p(0.0), prev(0.0), curRound(-1) {}
    double get(int round) { return round < curRound ? prev : p; }
    bool updated(int round) { return curRound >= round; }
    void add(int round, double val) {
        if(curRound < round) {
            prev = p; // store
            p = val; // start from zero
            curRound = round;
        } else p += val;
    }
};

int main() {
    vector<Prob> P(0x20000); // probability for all possible states
    deque<unsigned int> states; // active states
    int nzeros[256]; // simple lookup
    int x, k;
    double p, val;
    Index st = { .i = 0 };

    // Precalc amount of zeros for nonzero bytes
    FORE(z,0,7)
        FOR(h,0,1<<(7-z))
            nzeros[(h*2+1) << z] = z;

    cin >> x >> k >> p;
    p /= 100.0;

    // Calculate initial state
    st.st.low8 = x & 255;
    st.st.ones = (x >> 8) & 1;
    for(st.st.n = 1, x>>=9; st.st.n < 24 && (x&1) == st.st.ones; ++st.st.n, x>>=1) {}

    states.push_back(st.i);
    P[st.i].add(0, 1.0);

    FORE(r,1,k) {
        REP(states.size()) { // process current states
            st.i = states.front(); // reset

            if((val = P[st.i].get(r-1) * p) > 1e-15) { // Handle *= 2
                st.st.n = ((st.st.low8 >> 7) == st.st.ones) ? st.st.n + 1 : 1;
                st.st.ones = st.st.low8 >> 7; // this will be shifted out
                st.st.low8 <<= 1;

                if(!P[st.i].updated(r)) // state not yet reached on this round
                    states.push_back(st.i);
                P[st.i].add(r, val); // set/increment
            }

            st.i = states.front(); // reset

            if((val = P[st.i].get(r-1) * (1-p)) > 1e-15) { // Handle += 1
                if(++st.st.low8 == 0) { // one to be added above low8
                    if(!st.st.ones) st.st.n = 1; // ones become zeros
                    st.st.ones ^= 1; // type changes
                }

                if(!P[st.i].updated(r)) // state not yet reached on this round
                    states.push_back(st.i);
                P[st.i].add(r, val); // set/increment
            }

            states.pop_front(); // destroy
        }
    }

    val = 0; // expected value
    for(unsigned int i : states) {
        st.i = i;
        if(st.st.low8)
            val += P[i].get(k) * nzeros[st.st.low8];
        else
            val += P[i].get(k) * ((st.st.ones ? 0 : st.st.n) + 8);
    }

    cout.precision(35);
    cout << val << endl;

    return 0;
}
