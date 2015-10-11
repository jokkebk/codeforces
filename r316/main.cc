#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))

char s[500005];

vector<int> p, height, ccnt, start;
vector<map<int,int>> mask;

bool pali(int h, int from, int to, bool debug) {
    auto begin = mask[h].lower_bound(from), end = mask[h].lower_bound(to);

    if(debug) cout << h << ": From " << from << " to " << to << endl;

    if(begin == mask[h].end()) {
        if(debug) cout << "Beyond this range!" << endl;
        return true;
    } else {
        if(debug) cout << (begin==mask[h].end()) << " and " << end->first << " = " << end->second << endl;
        if(debug) cout << "btw. " << (end==mask[h].end()) << endl;
        int before = (begin == mask[h].begin() ? 0 : (--begin)->second), after;
        if(debug) cout << "Before this is " << before << endl;
        if(end == mask[h].end()) {
            if(debug) cout << "Range contains last element which is " << mask[h].rbegin()->second << endl;
            after = mask[h].rbegin()->second;
        } else if(end->first > to) {
            if(debug) cout << "Outside this range!" << endl;
            return true;
        } else {
            after = end->second;
        }
        if(debug) cout << "At the end is " << after << endl;
        int within = before ^ after;
        return !(within && (within&(within-1)));
    }
}

int main() {
    int n, m, v, h, hmax=0;

    S(n); S(m);
    p.resize(n);
    height.resize(n);
    ccnt.resize(n);
    start.resize(n);

    FOR(i,1,n) {
        S(p[i]); p[i]--;
        height[i] = height[p[i]] + 1;
        hmax = MAX(hmax, height[i]);
    }

    REP(2) fgets(s, sizeof(s)-2, stdin);

    mask.resize(hmax+1); // simplify indexing

    // Count children
    for(int i=n-1; i; i--) ccnt[p[i]] += ccnt[i] + 1;

    // Renumber nodes so subtree starts from start[v] plus ccnt[v] children
    start[0] = ccnt[0]; // Enough for all children
    FOR(i,1,n) {
        start[i] = start[p[i]]; // Begin range from here
        //cout << "Store " << s[i] << " (" << (1<<(s[i]-'a')) << ") at " << height[i] << " / " << start[i] << endl;
        mask[height[i]][start[i]] = 1 << (s[i]-'a'); // stays within range
        start[p[i]] -= ccnt[i] + 1; // Reserve numbers for this and children
    }

    //FOR(i,0,n) cout << "Node " << i+1 << ": " << start[i] << " .. " << start[i]+ccnt[i] << endl;

    FORE(i,1,hmax) {
        int last = 0;
        //cout << "Height " << i << endl;
        for(auto& it : mask[i]) {
            it.second ^= last;
            //cout << "  " << it.first << " = " << it.second << endl;
            last = it.second;
        }
    }

    FOR(i,0,m) {
        S(v); v--;
        S(h); h--;

        //if(n == 500000 && m == 500000 && i == 13)
            //cout << "Tree of height " << hmax << " asking for " << v << " " << h << " subtree at height " << height[v] << endl;

        if(h <= height[v] || h > hmax)
            cout << "Yes" << endl;
        else
            cout << (pali(h, start[v], start[v]+ccnt[v], false && (n == 500000 && m == 500000 && i == 13)) ? "Yes":"No") << endl;

    }

    return 0;
}
