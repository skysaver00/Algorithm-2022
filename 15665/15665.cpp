#include <iostream>
#include <algorithm>

using namespace std;
int arr[10];
int brr[10];

void go(int index, int n, int m) {
    if(index == m) {
        for(int i = 0; i < m; i++) cout << brr[arr[i]] << ' ';
        cout << "\n";
        return;
    }

    for(int i = 0; i < n; i++) {
        arr[index] = i;
        go(index + 1, n, m);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int temp[10];
    for(int i = 0; i < n; i++) cin >> temp[i];
    sort(temp, temp + n);
    int now = 0;
    brr[now] = temp[0];
    for(int i = 1; i < n; i++) {
        if(brr[now] == temp[i]) continue;
        else {
            now++;
            brr[now] = temp[i];
        }
    }
    go(0, now + 1, m);
}