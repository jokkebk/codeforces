#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef unsigned long long ULL;

struct RangeTree { // binary tree of volume ranges
    RangeTree *low, *high;
    ULL tofill;
    int tubes, from, to, lowto;

    static RangeTree * create(int from, int to) {
        static vector<RangeTree> pool(30 * 100000);
        static int next = 0;

        RangeTree *r = &pool[next++];
        r->init(from, to);
        return r;
    }

    RangeTree() : low(NULL), high(NULL), tofill(0), tubes(0) {}

    void init(int f, int t) {
        from = f; to = t;
        lowto = (from + to) / 2;
    }

    void add(int v) { // Add a tube with v liters of mercury
        tofill += (ULL)(to - v);
        tubes++;
        if(from != to) { // subtrees
            RangeTree *r = v > lowto ? high : low;

            if(r == NULL) {
                if(v > lowto)
                    r = high = RangeTree::create(lowto+1, to);
                else
                    r = low = RangeTree::create(from, lowto);
            }

            r->add(v);
        }
    }

    void remove(int v) { // Remove a tube with v liters of mercury
        tofill -= (ULL)(to - v);
        tubes--;
        if(from != to) { // subtrees must exist
            RangeTree *r = v > lowto ? high : low;
            r->remove(v);
        }
    }
};

double query(RangeTree *r, ULL water) {
    ULL tubes = 0, level = 0;
    ULL left = water;

    while(r != NULL) {
        ULL needed = tubes * (r->to - level) + r->tofill;

        if(left > needed) { // can fill it all
            left -= needed; // decrease water
            tubes += r->tubes; // add tubes
            level = r->to;
            break;
        }

        if(r->low == NULL) { // only high
            r = r->high;
        } else { // low side exists
            needed = tubes * (r->low->to - level) + r->low->tofill;

            if(left < needed) {
                r = r->low;
            } else {
                left -= needed; // decrease water
                tubes += r->low->tubes; // add tubes
                level = r->low->to; // raise level
                r = r->high; // if left  < r->tofill, this must exist
            }
        }
    }

    return (double)level + (double)left/tubes;
}

int main() {
    RangeTree *r = RangeTree::create(0, (1<<30)-1);
    vector<int> h;
    int n, q, t, p, x;
    ULL v;

    cin >> n >> q;

    h.reserve(n+1);

    FORE(i, 1, n) {
        cin >> h[i];
        r->add(h[i]);
    }

    FOR(i, 0, q) {
        cin >> t;
        if(t == 1) { // replace
            cin >> p >> x;
            r->remove(h[p]);
            h[p] = x;
            r->add(h[p]);
        } else { // query
            cin >> v;
            cout << setprecision(35) << query(r, v) << endl;
        }
    }

    return 0;
}
