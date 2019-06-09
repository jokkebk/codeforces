#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

typedef long long LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;
    map<int, LL> best, outcomes;

    best[0] = 0;


    for(int i=0; i<n; i++) {
        int k;
        cin >> k;
        vector<LL> cards[3];
        for(int j=0; j<k; j++) {
            int c, d;
            cin >> c >> d;
            cards[c-1].push_back(d);
        }
        vector<tuple<int,LL,LL,LL>> brute;

        for(int j=0; j<3; j++) if(cards[j].size()) { // One card
            sort(cards[j].rbegin(), cards[j].rend());
            brute.push_back(make_tuple(1, cards[j][0], 0, 0));
        }
        if(cards[0].size() && cards[1].size()) { // Two cards, 2+1
            int mi = min(cards[0][0], cards[1][0]);
            int ma = max(cards[0][0], cards[1][0]);
            brute.push_back(make_tuple(2, ma, mi, 0));
        }
        if(cards[0].size() > 1) // Two cards, 1+1
            brute.push_back(make_tuple(2, cards[0][0], cards[0][1], 0));
        if(cards[0].size() > 2) // Three cards, 1+1+1
            brute.push_back(make_tuple(3, cards[0][0], cards[0][1], cards[0][2]));

        //map<int, LL> outcomes(best);
        outcomes = best;

        if(true) for(auto t : brute) {
            //cout << get<0>(t) << " * (" << get<1>(t) << ", " << get<2>(t) << ", " << get<3>(t) << ") " << endl;
            for(auto p : best) {
                LL pts;
                int n, len;
                tie(n, pts) = p;
                //cout << n << " / " << pts << " pts" << endl;
                len = get<0>(t); // number of items
                n += len;
                pts += get<1>(t);
                if(len>1) pts += get<2>(t);
                if(len>2) pts += get<3>(t);
                if(n >= 10) {
                    n -= 10;
                    pts += get<1>(t); // double up
                }
                outcomes[n] = max(outcomes[n], pts);
                if(outcomes.size() > 10) {
                    cout << "JUMALAUTA!" << endl;
                    return 1;
                }
            }
        }

        //cout << "After" << endl;
        //for(auto p : outcomes) cout << p.first << " " << p.second << endl;
        best = outcomes;

    }
    auto maxV = max_element(best.begin(), best.end(), [](const pair<int, LL>& p1, const pair<int, LL>& p2) {
        return p1.second < p2.second; });
    cout << maxV->second << endl;
}

