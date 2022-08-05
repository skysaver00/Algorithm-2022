#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int ans = 0;
    
    for(int i = 1; i <= n; i++) {
        if(i % 5 == 0) ans++;
        if(i % 25 == 0) ans++;
        if(i % 125 == 0) ans++;
    }

    std::cout << ans;
    return 0;
}