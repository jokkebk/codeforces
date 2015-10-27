#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

#define REP(n) for(__typeof(n) _i=0; _i<(n); ++_i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<b; ++i)
#define FORE(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define S(x) scanf("%d", &(x))

typedef long long LL;

#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))
#define ABS(a) (((a)<0) ? -(a) : (a))
#define SWAP(a,b) {a ^= b; b ^= a; a ^= b; }

#define Inf 1000000007

int d[3][1024][1024];

int main() {
    vector<string> mp;
    pair<int,int> start[3];
    deque<pair<int,int>> q;
    int n, m;

    cin >> n >> m;

    vector<vector<char>> M(n+2, vector<char>(m+2,'#'));

    FORE(i,1,n) {
        string s;
        cin >> s;
        FORE(j,1,m) {
            M[i][j] = s[j-1];
            if(s[j-1]>='1'&&s[j-1]<='3') start[s[j-1]-'1'] = make_pair(i,j);
        }
    }

    FOR(i,0,3) {
        FORE(j,1,n) FORE(k,1,m) d[i][j][k] = Inf; // Initialize

        q.push_back(start[i]);
        d[i][start[i].first][start[i].second] = 0;

        while(q.size()) {
            int x=q.front().first, y=q.front().second, dist=d[i][x][y];
            q.pop_front();

            for(int dx=1, dy=0, r=0, t; r<4; r++, t=dy, dy=-dx, dx=t) {
                if(M[x+dx][y+dy]=='#' || d[i][x+dx][y+dy] < Inf) continue;
                if(M[x+dx][y+dy]=='.') { // road needed
                    q.push_back(make_pair(x+dx,y+dy));
                    d[i][x+dx][y+dy] = dist+1;
                } else { // state
                    q.push_front(make_pair(x+dx,y+dy));
                    d[i][x+dx][y+dy] = dist;
                }
            }
        }
    }

    LL min=Inf;
    FORE(x,1,n) FORE(y,1,m) min=MIN(min, (LL)d[0][x][y] + d[1][x][y] + d[2][x][y] +
            (M[x][y]=='.'?-2:0));

    cout << (min<Inf ? min : -1) << endl;

    return 0;
}
