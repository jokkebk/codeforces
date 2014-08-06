#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <tuple>

using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; ++i)

struct UnionFind {
    UnionFind *parent;
    int rank, value;
    bool done;

    UnionFind() : parent(this), rank(0), done(false) {}

    UnionFind *root() { return (parent == this) ? this : parent->root(); }

    void join(UnionFind & other) {
        UnionFind *x = other.root(), *y = root();

        if(x == y) return;

        if(x->rank < y->rank)
            x->parent = y;
        else {
            y->parent = x;
            if(x->rank > y->rank)
                x->rank++;
        }
    }

    void recurseResults(vector<pair<int,int>> & pairs) {
        if(done || parent == this) return; // skip done and root
        parent->recurseResults(pairs); // parents first
        pairs.push_back(make_pair(value, parent->value));
        done = true;
    }
} level[1000];

int getDiff(char *s, int w, int i, int j) {
    char *a = s + i*w, *b = s + j*w, diff = 0;
    FOR(k,0,w) if(*a++ != *b++) diff++;
    return diff;
}

int main() {
    priority_queue< tuple<int,int,int> > pq;
    vector<pair<int,int>> pairs;
    int n, m, k, w, change = 0;
    char s[100005];

    cin >> n >> m >> k >> w;

    FOR(y,0,n*k) cin >> &s[y*m];

    FOR(i,0,k) {
        level[i].value = i; // avoid pointer math
        FOR(j,0,i) pq.push(make_tuple(-getDiff(s, n*m, i, j), i, j));
    }

    while(!pq.empty()) {
        int diff = -get<0>(pq.top()),
            i = get<1>(pq.top()), j = get<2>(pq.top());
        pq.pop();
        //cout << i << "/" << j << " (" << diff << ")" << endl;
        if(diff * w >= n * m) {
            //cout << "Not useful anymore!" << endl;
            break;
        }
        if(level[i].root() == level[j].root()) {
            //cout << "Already together!" << endl;
        } else {
            level[i].join(level[j]);
            change += diff * w;
        }
    }

    pairs.reserve(2*k);
    FOR(i,0,k) level[i].recurseResults(pairs);

    FOR(i,0,k) if(!level[i].done) change += n * m;

    cout << change << endl;

    FOR(i,0,k) if(!level[i].done) cout << i+1 << " 0" << endl;

    for(auto p : pairs) cout << p.first+1 << " " << p.second+1 << endl;

    return 0;
}
