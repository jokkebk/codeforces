#include <iostream>
#include <vector>
#include <tuple>
#include <set>

using namespace std;

struct UnionFind {
    struct UF_elem { int size; int parent; };
    vector<UF_elem> el;
    
    UnionFind(int n) { // Adds el 0..n-1
        el.resize(n);
        for(int i = 0; i < el.size(); i++) {
            el[i].parent = i;
            el[i].size = 1;
        }
    }

    int find(int id) {
        while(el[id].parent != id) id = el[id].parent;
        return id;
    }

    bool join(int id1, int id2) {
        int p1 = find(id1);
        int p2 = find(id2);
        UF_elem& E1 = el[p1];
        UF_elem& E2 = el[p2];
        if(p1 == p2) return false;
        if(E1.size < E2.size) {
            E1.parent = p2;
            E2.size += E1.size;
        } else {
            E2.parent = p1;
            E1.size += E2.size;
        }
        return true;
    }

    int size(int id) { return el[find(id)].size; }
};

int main() {
    int t, n, m, a, b;

    cin >> t;

    while(t--) {
        cin >> n >> m;
        UnionFind uf(n+1); // connectedness, 1 indexed
        vector<set<int>> e(n+1); // edges to other nodes, 1 indexed
        vector<int> p(n+1); // parents, 1 indexed
        vector<pair<int,int>> cycles;

        while(m--) {
            cin >> a >> b;
            if(uf.join(a,b)) { // nodes not connected yet
                e[a].insert(b);
                e[b].insert(a);
            } else cycles.push_back({a,b}); // save cycles for later
        }


        for(int i=1; i<=n; i++) { // Make it a forest!
            if(p[i]) continue; // already in a tree
            vector<int> q = {i}; // queue
            while(q.size()) {
                int n = q.back(); q.pop_back();
                for(int ch : e[n]) {
                    if(ch == p[n]) continue; // skip parent
                    p[ch] = n;
                    q.push_back(ch);
                }
            }
        }

        set<int> incycle;
        bool done = false;
        for(auto ab : cycles) { // Now mark cycles
            vector<int> ap, bp;
            tie(a, b) = ab;
            do { ap.push_back(a); a = p[a]; } while(a);
            do { bp.push_back(b); b = p[b]; } while(b);
            int top = 0;
            while(ap.back() == bp.back()) {
                top = ap.back(); ap.pop_back(); bp.pop_back();
            }
            ap.push_back(top); // back into pile
            ap.insert(ap.end(), bp.begin(), bp.end());
            for(int n : ap) {
                if(incycle.count(n)) {
                    cout << "YES" << endl;
                    done = true;
                    break;
                }
                incycle.insert(n);
            }
            if(done) break;
        }
        if(!done) cout << "NO" << endl;
    }
}
