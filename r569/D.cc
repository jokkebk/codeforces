#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // F
  cin.tie(NULL); // U
  int m, n;
  cin >> n >> m;
  for(int r=0; r<(n+1)/2; r++) {
    for(int c=0; c<m; c++) {
      if(r+1 == n-r && c+1 > m-c) break;
      cout << r+1 << " " << c+1 << "\n"; // C
      if(r+1 == n-r && c+1 == m-c) break;
      cout << n-r << " " << m-c << "\n"; // F
    }
  }
}
