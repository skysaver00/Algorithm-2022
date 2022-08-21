#include <iostream>
#include <algorithm>

using namespace std;
int arr[10];
int brr[10];
bool cnt[10];

void go(int index, int n, int m) {
    if(index == m) {
        for(int i = 0; i < m; i++) cout << brr[arr[i]] << ' ';
        cout << "\n";
        return;
    }

    for(int i = 0; i < n; i++) {
        if(cnt[i]) continue;
        cnt[i] = true;
        arr[index] = i;
        go(index + 1, n, m);
        cnt[i] = false;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> brr[i];
    sort(brr, brr + n);
    go(0, n, m);
}