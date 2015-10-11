#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

int pali(int v, int h, bool debug) {
    if(h == height[v])
        return 1<<(s[v]-'a');
    else if(h < height[v] || h >= mask.size())
        return 0;

    int from=start[v], to=start[v]+ccnt[v];
    auto begin = mask[h].lower_bound(from), end = mask[h].lower_bound(to);

    if(debug) cout << h << ": From " << from << " to " << to << endl;

    if(begin == mask[h].end()) {
        if(debug) cout << "Beyond this range!" << endl;
        return 0;
    } else {
        if(debug) cout << (begin==mask[h].end()) << " and " << end->first << " = " << end->second << endl;
        if(debug) cout << "btw. " << (end==mask[h].end()) << endl;
        int before = (begin == mask[h].begin() ? 0 : (--begin)->second), after;
        if(debug) cout << "Before this is " << before << endl;
        if(end == mask[h].end()) {
            if(debug) cout << "Range contains last element which is " << mask[h].rbegin()->second << endl;
            after = mask[h].rbegin()->second;
        } else if(end->first > to) {
            if(end == mask[h].begin()) return 0; // cannot rewind
            end--;
            after = end->second;
            //if(debug) cout << "Outside this range!" << endl;
            //return 0;
        } else {
            after = end->second;
        }
        if(debug) cout << "At the end is " << after << endl;
        return before ^ after;
    }
}

vector<vector<int>> C(11);

int brute(int v, int h) {
    //cout << "Brute forcing vertex " << v+1 << " (h=" << height[v] << ") to height " << h+1 << endl;

    if(height[v] > h) return 0;
    if(height[v] == h) return 1<<(s[v]-'a');

    int mask = 0;
    for(int c : C[v]) mask ^= brute(c, h);
    return mask;
}

void ptree(int v) {
    static char ind[21] = "                    ";
    cout << &ind[20-height[v]*2];
    cout << v+1 << "/" << start[v] << " (h=" << height[v]+1 << "): " << s[v] << " (" << (1<<(s[v]-'a')) << ")" << endl;
    for(int c : C[v]) ptree(c);
}

int main() {
    int n, m, v, h, hmax=0;
    bool sim = false;

    srand(time(NULL));
    bool quit = false;
    while(!quit) {
        if(!sim) {
            S(n); S(m);
            quit = true;
        } else {
            // TODO: remove
            n = 10; m = 5;
            p.clear();
            height.clear();
            ccnt.clear();
            start.clear();
            C.clear();
            C.resize(n);
        }

        p.resize(n);
        height.resize(n);
        ccnt.resize(n);
        start.resize(n);

        if(sim) cout << "10 10" << endl;

        FOR(i,1,n) {
            if(!sim) {
                S(p[i]); p[i]--;
            } else {
                p[i] = rand() % i;
                cout << p[i]+1 << " ";
                C[p[i]].push_back(i); // TODO: Remove
            }

            height[i] = height[p[i]] + 1;
            hmax = MAX(hmax, height[i]);
        }
        if(sim) cout << endl;
        if(sim) cout << "abbabbabba" << endl;

        if(!sim) {
            REP(2) fgets(s, sizeof(s)-2, stdin);
        } else {
            strcpy(s, "abbabbabba");
            mask.clear(); // TODO: Remove
        }

        mask.resize(hmax+1); // simplify indexing

        // Count children
        for(int i=n-1; i; i--) ccnt[p[i]] += ccnt[i] + 1;

        // Renumber nodes so subtree starts from start[v] plus ccnt[v] children
        start[0] = ccnt[0]; // Enough for all children
        FOR(i,1,n) {
            start[i] = start[p[i]]; // Begin range from here
            //cout << "Store " << s[i] << " (" << (1<<(s[i]-'a')) << ") at " << height[i] << " / " << start[i] << endl;
            start[p[i]] -= ccnt[i] + 1; // Reserve numbers for this and children
        }

        FOR(i,1,n)
            mask[height[i]][start[i]] = 1 << (s[i]-'a'); // stays within range

        if(sim) ptree(0);

        //FOR(i,0,n) cout << "Node " << i+1 << ": " << start[i] << " .. " << start[i]+ccnt[i] << endl;

        FORE(i,1,hmax) {
            int last = 0;
            if(sim) cout << "mask[" << i << "]: ";
            for(auto& it : mask[i]) {
                it.second ^= last;
                if(sim) cout << it.first << "=" << it.second << " ";
                last = it.second;
            }
            if(sim) cout << endl;
        }

        FOR(i,0,m) {
            if(!sim) {
                S(v); v--;
                S(h); h--;
            } else {
                v = rand() % n;
                h = height[v]+1+rand()%3;
                cout << v+1 << " " << h+1 << endl;
            }

            //if(n == 500000 && m == 500000 && i == 13)
            //cout << "Tree of height " << hmax << " asking for " << v << " " << h << " subtree at height " << height[v] << endl;

            int ans = pali(v, h, false);
            if(sim) {
                int alt = brute(v, h);

                if(ans != alt) {
                    cout << "FAIL " << ans << " vs. " << alt << endl;
                    int from=start[v], to=start[v]+ccnt[v];
                    pali(v, h, true);
                    quit = true;
                }
            }

            cout << (!(ans && (ans&(ans-1))) ? "Yes":"No") << endl;

        }
        cout << endl;
    }

    return 0;
}
