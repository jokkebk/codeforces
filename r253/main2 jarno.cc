#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
//#include <tuple>
#include <limits>

using namespace std;

int check(string& s, int k, int start, int end){
    int L = end-start+1;
    if(L%2 != 0) return false;
    int n = L/2;
    int result = 0;
    //cout << n << endl;
    for(int i = start; i + n <= end; i++){
        //cout << i << " " << i+n << endl;
        if(i+n > end) {return result;}
        if(i+n >= s.size()) {result++; continue;}
        if(s[i] != s[i+n]) {return result;}
        result++;
    }
    return result;
}


int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    //int len = s.size();
    //check(s,k,0,5); return 0;
    int best = 0;
    for(int start = 0; start < s.size() + k; start++){
        for(int end = start + 1; end < s.size() + k; end++){
            best = max(best,check(s,k,start,end));
        } 
    }
    cout << best * 2 << endl;;
}