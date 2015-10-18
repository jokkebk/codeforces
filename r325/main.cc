#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))
#define SWAP(a,b) {a ^= b; b ^= a; a ^= b;}

#define Inf 1000000007

struct Int256 {
    uint32_t n[8];

    Int256(const unsigned long long n=0) {
        this->n[0] = n & 0xFFFFFFFFLL;
        this->n[1] = n >> 32LL;
        for(int i=2; i<8; i++) this->n[i] = 0;
    }

    Int256(const Int256 &o) {
        for(int i=1; i<8; i++) this->n[i] = o.n[i];
    }

    const bool operator<(const Int256 &o) const {
        this->print();
        puts("vs.");
        o.print();
        for(int i=7; i>=0; i--) if(this->n[i] < o.n[i]) return true;
        return false;
    }

    Int256 operator+(const Int256 &o) {
        Int256 s;
        unsigned long long carry=0;
        for(int i=0; i<8; i++) {
            carry = (unsigned long long)this->n[i] + o.n[i];
            s.n[i] = carry & 0xFFFFFFFFLL;
            carry >>= 32LL;
        }
        return s;
    }

    void add(int i, uint32_t n) {
        unsigned long long carry = (unsigned long long)n + this->n[i];

        //if(n) printf("add(%d, %08X)\n", i, n);

        while(carry && i<8) {
            this->n[i] = carry & 0xFFFFFFFFLL;
            carry >>= 32LL;
        }
    }

    Int256 operator*(const Int256 &o) {
        Int256 s;
        unsigned long long carry=0;
        for(int i=0; i<8; i++) {
            for(int j=0; i+j<8; j++) {
                carry = (unsigned long long)this->n[i] * o.n[j];
                s.add(i+j, carry & 0xFFFFFFFFLL);
                s.add(i+j+1, carry >> 32LL);
            }
        }
        return s;
    }

    void print() const {
        for(int i=0; i<8; i++) printf("%08X ", this->n[7-i]);
        puts("");
    }
};

int main() {
    LL x1, y1;
    Int256 ax=1, ay=0, bx=0, by=1;
    char ch[2];

    cin >> x1 >> y1;

    Int256 x=x1, y=y1;

    bool anext = (x1>y1);
    ch[0] = x1>y1 ? 'A' : 'B';
    ch[1] = x1>y1 ? 'B' : 'A';

    vector<LL> ans;

    while(ax+ay+bx+by < x+y) {
        //cout << ax << "," << ay << " .. " << bx << "," << by << endl;
        if(anext) {
            // Add ax,ay to bx,by so many times that x/y is between
            // bx+n*ax / by+n*ay and bx+(n+1)*ax / by+(n+1)*ay
            LL n=0;
            for(LL i=1LL<<59LL; i>0LL; i/=2LL)
                if(y*(bx + Int256(n+i)*ax) < x*(by + Int256(n+i)*ay))
                    n += i;
            if(!n) {
                cout << "Impossible" << endl;
                return 0;
            }
            ans.push_back(n);
            bx = bx + Int256(n)*ax;
            by = by + Int256(n)*ay;
        } else {
            LL n=0;
            for(LL i=1LL<<59LL; i>0LL; i/=2LL)
                if(x*(ay + Int256(n+i)*by) < y*(ax + Int256(n+i)*bx))
                    n += i;
            if(!n) {
                cout << "Impossible" << endl;
                return 0;
            }
            ans.push_back(n);
            ax = ax + Int256(n)*bx;
            ay = ay + Int256(n)*by;
        }
        anext = !anext;
    }

    FOR(i,0,ans.size()) cout << ans[i] << ch[i&1];
    cout << endl;

    return 0;
}
