#include <iostream>
long long arr[1000001];

int main() {
    int t;
    std::cin >> t;

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for(int i = 4; i <= 1000000; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
        arr[i] %= 1000000009;
    }

    while(t--) {
        int i;
        std::cin >> i;

        std::cout << arr[i] << std::endl;
    }
    return 0;
}