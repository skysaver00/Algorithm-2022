#include <iostream>
using namespace std;
int arr[10];
int res[10];
bool visit[10];

void NnM(int cnt, int m, int n) {
    if(cnt == m) {
        for(int i = 0; i < cnt; i++) {
            cout << res[i] << " ";
        }cout << "\n";

        return;
    }

    for(int i = 0; i < n; i++) {
        if(visit[i]) continue;
        res[cnt] = arr[i];
        visit[i] = true;
        NnM(cnt + 1, m, n);
        visit[i] = false;
    }
}

int main() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) arr[i] = i + 1;

    NnM(0, m, n);
    return 0;
}