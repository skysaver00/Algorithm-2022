#include <iostream>

using namespace std;
int arr[10];
bool c[10];

void go(int index, int n, int m) {
    if(index == m) {
        for(int i = 0; i < m; i++) cout << arr[i] << ' ';
        cout << "\n";
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(c[i]) continue;
        c[i] = true;
        arr[index] = i;
        go(index + 1, n, m);
        c[i] = false;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    go(0, n, m);
}