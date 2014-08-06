#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

int main() {
    char s[102], t[102], m[102];
    int c[256];
    int n, spos;
    bool automaton = false, array = false;

    cin >> s >> t;

    FOR(i,0,256) c[i] = 0;

    for(int i=0; s[i]; ++i)
        c[s[i]]++; // count each char occurances

    for(int i=0; t[i]; ++i)
        c[t[i]]--; // decrease for every letter needed

    FOR(i,0,256) {
        if(c[i] < 0) { // too few chars
            cout << "need tree";
            return 0;
        } else if(c[i] > 0)
            automaton = true; // at least removal needed
    }

    spos = strlen(s) - 1;
    for(int i = strlen(t) - 1; i >= 0; i--) {
        while(spos >= 0 && s[spos] != t[i])
            spos--;

        if(spos < 0) {
            array = true;
            break;
        } else spos--; // next char
    }

    if(automaton && array)
        cout << "both";
    else if(automaton)
        cout << "automaton";
    else if(array)
        cout << "array";
    else
        cout << "none"; // not in specs, but...

    return 0;
}
