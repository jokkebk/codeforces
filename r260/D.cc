#include <iostream>
#include <map>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

struct Tree {
    map<char,Tree *> leaves;

    void store(char *s) {
        if(!*s) return;

        auto leaf = leaves.find(*s);

        if(leaf == leaves.end()) {
            Tree *t = new Tree();
            leaves[*s] = t;
            t->store(s+1);
        } else leaf->second->store(s+1);
    }

    pair<bool,bool> getType(bool aTurn) {
        bool canWin = !aTurn, canLose = !aTurn; // correct base for & / |

        if(leaves.empty()) return make_pair(!aTurn, aTurn);

        for(auto it : leaves) {
            pair<bool,bool> type = it.second->getType(!aTurn);

            if(aTurn)
                canWin |= type.first, canLose |= type.second;
            else
                canWin &= type.first, canLose &= type.second;
        }

        return make_pair(canWin, canLose);
    }
};

char s[100005];

int main() {
    Tree *root = new Tree();
    int n, k;

	cin >> n >> k;
    REP(n) cin >> s, root->store(s);

    pair<bool,bool> type = root->getType(true);

    if(type.first && type.second) // A can win & lose
        cout << "First" << endl;
    else if(!type.first) // A can't win
        cout << "Second" << endl;
    else // A can win
        cout << ((k&1) ? "First" : "Second") << endl;

    return 0;
}
