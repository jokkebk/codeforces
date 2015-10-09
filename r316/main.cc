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

char s[500010];

vector<vector<int>> C;
vector<int> height, line, top, before;
priority_queue<tuple<int,int,int>> hsorted;

void rec(int v, int indent) {
    static char ind[21] = "                    ";
    cout << &ind[20-indent*2] << s[v] << " (" << v << ") at h=" << height[v] << endl;
    if(line[v]) {
        cout << &ind[20-indent*2] << "..";
        FOR(i,0,line[v]) cout << C[v][i] << ".."; cout << endl;
        rec(C[v][line[v]], indent+1); // extract last item in line
    } else for(int c : C[v]) {
        rec(c, indent+1);
    }
}

int find(int v, int h, bool right) {
    //cout << "Going down from " << v << " to " << h << " levels" << endl;
    if(!h) return v;

    int t = top[v], l = line[t];

    if(l) {
        int pos = height[v] - height[t] - 1;
        //cout << "Supposedly we're at " << pos << "/" << line[t] << " from " << t << endl;
        if(pos+h <= l)
            return C[t][pos+h];
        else
            return find(C[t][l], h - (l-pos), right);
    } else {
        if(C[v].empty()) return 0;
        return find(right ? C[v].back() : C[v][0], h-1, right);
    }
}

int main() {
    int n, m, v, h;

    S(n); S(m);
    C.resize(n);
    height.resize(n);
    before.resize(n);
    line.resize(n);
    top.resize(n);

    FOR(i,1,n) {
        S(v), v--;
        C[v].push_back(i);
        height[i] = height[v]+1;
        hsorted.push(make_tuple(height[i], v, i));
        top[i] = v;
    }

    REP(2) fgets(s, sizeof(s)-2, stdin);

    // Flatten parts of trees with single child
    FOR(i,0,n) {
        if(C[i].size() == 1 && !line[top[i]]) {
            int c = C[i][0], cn;
            while(C[c].size() == 1) {
                cn = C[c][0];
                //cout << "Merge " << cn << " to " << i << endl;
                C[i].push_back(cn);
                line[i]++;
                top[cn] = i;
                c = cn;
            }
        }
    }

    //rec(0, 0);

    int curh=0, sofar=0;
    while(hsorted.size()) {
        tuple<int,int,int> t = hsorted.top(); hsorted.pop();
        h = get<0>(t);
        v = get<2>(t);
        if(h != curh) {
            sofar=0;
            curh=h;
        }
        before[v] = sofar;
        sofar ^= 1 << (s[v] - 'a');
        //cout << "Height " << get<0>(t) << " vertex " << v << " before " << before[v] << endl;
    }

    REP(m) {
        S(v); v--;
        S(h); h--;
        int hd = h-height[v];

        if(hd <= 0) cout << "Yes" << endl;
        else {
            int left = find(v, hd, false),
                right = find(v, hd, true),
                mask = before[left] ^ before[right] ^ (1<<(s[left] - 'a'));
            //cout << hd << " levels from " << v << " got " << left << ".." << right << " = " << before[left] << " ^ " << before[right] << " ^ " << (1<<(s[left] - 'a')) << " = " << mask << endl;
            cout << ((mask && (mask&(mask-1))) ? "No" : "Yes") << endl;
        }
    }

    return 0;
}
