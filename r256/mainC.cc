#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int from, to, minval;
    vector<Interval *> higher;
    Interval * lower = NULL;
};

int paint(Interval *i, int level) { // paint interval from level upwards
    int horizontal = i->minval - level;

    for(Interval *j : i->higher)
        horizontal += paint(j, i->minval);

    return min(i->to - i->from + 1, horizontal);
}

int main() {
    vector<int> a;
    vector<Interval> in;
    int ins = 0, n;

    cin >> n;

    a.resize(n+1); // adding 0 to end will help finding intervals
    in.resize(n+1); // room for bottom

    for(int i=0; i<n; ++i)
        cin >> a[i];
    a[n] = 0;

    Interval *bottom = &in[ins++], *i = &in[ins++];

    bottom->minval = 0; // from and to don't matter
    bottom->higher.push_back(i); // this is only thing that matters

    i->minval = a[0];
    i->from = i->to = 0;
    i->lower = bottom;

    for(int p=1; p<=n; ++p) {
        if(a[p] > i->minval) { // need to create higher
            Interval *j = &in[ins++]; // reserve

            j->from = p;
            j->minval = a[p];
            j->lower = i;

            i->higher.push_back(j);
            i = j; // continue with this
        } else while(a[p] < i->minval) { // get down
            Interval *j = i->lower;

            i->to = p - 1; // end current interval

            if(a[p] > j->minval) { // lower than i, larger than j
                Interval *m = &in[ins++]; // create a middle level m

                m->minval = a[p];
                m->from = i->from;
                m->higher.push_back(i);
                m->lower = j;

                i->lower = m;
                j->higher.back() = m; // replace higher with middle
                i = m; // replace i with m (also breaks out of loop)
            } else i = j;
        }
    }

    cout << paint(bottom->higher[0], 0); // no a[i] == 0 so real base above

    return 0;
}
