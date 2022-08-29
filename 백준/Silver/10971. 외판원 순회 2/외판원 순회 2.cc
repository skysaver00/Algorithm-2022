#include <iostream>

using namespace std;
int arr[11];
bool check[11];
int w[11][11];
int minimum = 2000000000;

void go(int index, int n, int m) {
    if(index == m) {
        int ans = 0;
        for(int i = 0; i < m - 1; i++) {
            if(w[arr[i]][arr[i + 1]] == 0) return;
            ans += w[arr[i]][arr[i + 1]];
        }
        if(w[arr[m - 1]][arr[0]] == 0) return;
        ans += w[arr[m - 1]][arr[0]];
        if(minimum > ans) minimum = ans;
        return;
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
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> w[i][j];
    }
    go(0, n, n);
    cout << minimum;
}