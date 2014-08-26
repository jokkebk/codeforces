#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

struct CountTree { // O(log n) adding, removing and counting of values
    CountTree *smaller = NULL, *larger = NULL;
    int num, count, less, more;

    CountTree(int n, int c) : num(n), count(c), less(0), more(0) {}

    void add(int n, int c) { // also works as remove with negative c
        if(n > num) {
            more += c;
            if(larger == NULL) larger = new CountTree(n, c);
            else larger->add(n, c);
        } else if(n < num) {
            less += c;
            if(smaller == NULL) smaller = new CountTree(n, c);
            else smaller->add(n, c);
        } else count += c; // n == num
    }

    int countLess(int n) {
        if(n > num) {
            return less + count + (larger != NULL ? larger->countLess(n) : 0);
        } else if(n < num) {
            if(smaller == NULL) return 0;
            else return smaller->countLess(n);
        } else return less; // n == num
    }
};

// Construct about-optimal count tree from sorted array
void construct(const vector<int> & v, int a, int b, CountTree & tree) {
    int mid = (a + b + 1) / 2; // b is inclusive, i.e. size-1 at beginning
    tree.add(v[mid], 1);
    if(mid > a) construct(v, a, mid-1, tree);
    if(mid < b) construct(v, mid+1, b, tree);
}

int main() {
    vector<int> a, fi, fj;
    map<int,int> c;
    LL n, count = 0;

    cin >> n;
    a.resize(n);
    fj.resize(n);

    FOR(i,0,n) { // precalc f(1, i, a_i) to fi
        cin >> a[i];
        fi.push_back(++c[a[i]]);
    }

    FOR(j,0,n) fj[j] = c[a[j]] - fi[j] + 1; // precalc f(j, n, a_j) to fj

    vector<int> v = fj; // make a copy of fj
    sort(v.begin(), v.end());

    CountTree tree(v[v.size()/2], 0); // pre-empt first item to have best root
    construct(v, 0, v.size()-1, tree);

    FOR(i,0,n-1) {
        tree.add(fj[i], -1); // remove current item from counts
        count += tree.countLess(fi[i]);
    }

    cout << count;

    return 0;
}
