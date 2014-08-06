#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

struct UnionFind {
    UnionFind *parent;
    int rank;
    UnionFind() : parent(this), rank(0) {}
    UnionFind *root() { return (parent == this) ? this : parent->root(); }
    bool join(UnionFind & other) { // returns false if already in same set
        UnionFind *x = other.root(), *y = root();
        if(x == y) return false;
        if(x->rank < y->rank)
            x->parent = y;
        else if(x->rank > y->rank)
            y->parent = x, x->rank++;
        else
            y->parent = x;
        return true;
    }
};

priority_queue< tuple<int,int,int> > pq;
vector<UnionFind> level(1001);
vector< vector<int> > neighbors(1001);
vector<bool> visited(1001, false);
vector< pair<int,int> > result;
int n, m, k, w, change = 0;
char s[100005];

int getDiff(int i, int j) {
    char *a = s + (i-1)*n*m, *b = s + (j-1)*n*m, d = 0;
    FOR(k,0,n*m) if(*a++ != *b++) d++;
    return d;
}

void makeTree(int p, int i) {
    if(visited[i]) return; // already visited
    else visited[i] = true; // now visited

    if(!p) {
        result.push_back(make_pair(i, 0));
        change += n * m;
    } else {
        result.push_back(make_pair(i, p));
        change += w * getDiff(i, p);
    }

    for(int j : neighbors[i]) makeTree(i, j);
}

int main() {
    cin >> n >> m >> k >> w;
    FOR(y,0,n*k) cin >> &s[y*m];

    FORE(i,1,k) FORE(j,i+1,k) {
        int d = getDiff(i, j);
        if(d * w < n * m) pq.push(make_tuple(-d, i, j));
    }

    while(!pq.empty()) {
        int i = get<1>(pq.top()), j = get<2>(pq.top());
        pq.pop();
        if(level[i].join(level[j])) {
            neighbors[i].push_back(j);
            neighbors[j].push_back(i);
        }
    }

    FORE(i,1,k) makeTree(0, i); // construct trees from graphs

    cout << change << endl;
    for(auto p : result) cout << p.first << " " << p.second << endl;

    return 0;
}
