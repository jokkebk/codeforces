#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

// store lengths for decreasing weights retaining previous value
struct Vertex {
	int len = 0, prevLen = 0, weight = 0;

	void setLen(int w, int l) {
		if(w < weight) prevLen = len; // store old value
		len = l, weight = w;
	}

	int getLen(int w) {
		return (w <= weight) ? len : prevLen; // new w starts at len
	}
};

int main() {
	int n, m, u, v, w, len, bestLen = 0;

	cin >> n >> m;

    vector< tuple<int,int,int> > edges;
	vector<Vertex> ve(n+1);

	REP(m) {
		cin >> u >> v >> w;
		edges.push_back(make_tuple(w, u, v));
	}

	sort(edges.rbegin(), edges.rend());

	for(auto t : edges) {
		w = get<0>(t), u = get<1>(t), v = get<2>(t);
		len = max(ve[u].getLen(w), ve[v].getLen(w+1) + 1);
		ve[u].setLen(w, len);
		bestLen = max(bestLen, len);
	}

	cout << bestLen << endl;

	return 0;
}
