#include <iostream>

using namespace std;
int arr[11];
bool check[11];
int w[11][11];

void go(int index, int n, int m) {
    if(index == m) {
        for(int i = 0; i < m; i++) cout << arr[i] << ' ';
        cout << '\n';
    }

    for(int i = 0; i < n; i++) {
        if(check[i]) continue;
        check[i] = true;
        arr[index] = i;
        go(index + 1, n, m);
        check[i] = false;
    }
}

int main() {
    go(0, 5, 5);
}