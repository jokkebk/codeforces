#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct UnionFind {
    int value;
    UnionFind *parent;
    int rank = 0;
    int items = 1;

    UnionFind(int val = 0) {
        this->value = val;
        this->parent = this;
    }

    void setValue(int val) { this->value = val; }

    UnionFind *find() { return (parent == this) ? this : parent->find(); }

    double combine(UnionFind & other) {
        UnionFind *x = other.find(), *y = find();
        double num;

        if(x == y) return 0;

        num = (double)x->items * (double)y->items; // new connections made

        if(x->rank < y->rank) {
            x->parent = y;
            y->items += x->items;
        } else if(x->rank > y->rank) {
            y->parent = x;
            x->items += y->items;
        } else {
            y->parent = x;
            x->items += y->items;
            x->rank++;
        }

        return num;
    }
};

UnionFind area[100000];

struct Connection {
    int a, b, val;

    void assign(const int & a, const int & b) {
        this->a = a;
        this->b = b;
        this->val = min(area[a].value, area[b].value);
    }

    bool operator < (const Connection & conn) const { return val < conn.val; }
};

Connection conn[100000];

int main() {
    int areas, roads, val, a, b;
    double sum = 0;
    vector<Connection> road;

    cin >> areas >> roads;

    for(int i=0; i<areas; i++) {
        cin >> val;
        area[i].setValue(val);
    }

    for(int i=0; i<roads; i++) {
        cin >> a >> b;
        conn[i].assign(--a, --b);
    }

    road.insert(road.begin(), conn, conn+roads);
    sort(road.rbegin(), road.rend());

    for(auto it = road.begin(); it != road.end(); it++)
        sum += (double)it->val * area[it->a].combine(area[it->b]);

    cout << 2.0 * sum / (double)areas / (double)(areas-1) << endl;

    return 0;
}
