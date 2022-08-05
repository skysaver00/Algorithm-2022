#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int val = 1;
    while(n > 1) {
        val *= n--;
    }

    std::cout << val;
}