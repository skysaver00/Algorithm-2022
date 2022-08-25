#include <iostream>
#include <algorithm>

using namespace std;
int ans[10];
int brr[10];
bool check[10];

void go(int index, int start, int n, int m) {
    if(index == m) {
        for(int i = 0; i < m; i++) cout << brr[ans[i]] << ' ';
        cout << '\n';
        return;
    }

    for(int i = start; i < n; i++) {
        if(check[i]) continue;
        check[i] = true;
        ans[index] = i;
        go(index + 1, i, n, m);
        check[i] = false;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> brr[i];
    sort(brr, brr + n);

    go(0, 0, n, m);
}