#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 2 * n - 1; i >= 1; i -= 2) {
        for(int j = 2 * n - 1 - i; j > 0; j -= 2) cout << ' ';
        for(int j = i; j > 0; j--) cout << '*';
        cout << "\n";
    }

    for(int i = 3; i <= 2 * n - 1; i += 2) {
        for(int j = 2 * n - 1 - i; j > 0; j -= 2) cout << ' ';
        for(int j = 0; j < i; j++) cout << '*';
        cout << "\n";
    }
}