#include <iostream>
#include <cstdlib>

int main() {
    int n;

    std::cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            std::cout << (abs(i-n/2) + abs(j-n/2) <= n/2 ? "D" : "*");
        std::cout << std::endl;
    }

    return 0;
}
