#include <iostream>

using namespace std;
int arr[8];
bool count[8];

void go(int index, int start, int n, int m) {
    if(index == m) {
        for(int i = 0; i < m; i++) cout << arr[i] << ' ';
        cout << "\n";
        return;
    }
    for(int i = start; i <= n; i++) {
        arr[index] = i;
        go(index + 1, i + 1, n, m);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    go(0, 1, n, m);
}