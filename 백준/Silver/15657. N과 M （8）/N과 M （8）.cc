#include <iostream>
#include <algorithm>

using namespace std;
int arr[10];
int brr[10];

void go(int index, int start, int n, int m) {
    if(index == m) {
        for(int i = 0; i < m; i++) cout << brr[arr[i]] << ' ';
        cout << "\n";
        return;
    }

    for(int i = start; i < n; i++) {
        arr[index] = i;
        go(index + 1, i, n, m);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> brr[i];
    sort(brr, brr + n);
    go(0, 0, n, m);
}