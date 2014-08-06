#include <iostream>
#include <vector>
#include <queue>

struct Way {
    bool train;
    int u, v;
    long long dist;
    bool operator<(Way const &w) const {
        if(dist == w.dist) return train;
        return dist > w.dist;
    }
};

int main() {
    std::vector<Way> way(400001);
    std::vector<bool> reached(100001, false);
    std::vector< std::vector<int> > roads(100001);
    std::priority_queue<Way> plan;
    int n, m, k, city, trainsUsed = 0;

    std::cin >> n >> m >> k;

    for(int i=0; i<m; ++i) {
        std::cin >> way[i].u >> way[i].v >> way[i].dist;
        way[i].train = false;
        roads[way[i].u].push_back(i);
        roads[way[i].v].push_back(i);
    }

    for(int i=0; i<k; ++i) {
        std::cin >> way[m + i].v >> way[m + i].dist;
        way[m + i].u = 1;
        way[m + i].train = true;
        roads[1].push_back(m + i); // no need for reverse
    }

    reached[1] = true;
    for(int i : roads[1]) plan.push(way[i]);

    while(n > 1 && !plan.empty()) {
        Way w = plan.top(); plan.pop();

        if(reached[w.u] && reached[w.v]) continue; // both reached

        city = reached[w.u] ? w.v : w.u;
        reached[city] = true, n--; // now reached
        if(w.train) trainsUsed++;

        for(int i : roads[city]) {
            way[i].dist += w.dist;
            plan.push(way[i]);
        }
    }

    std::cout << k - trainsUsed;

    return 0;
}
