#include <iostream>
#include <algorithm>

using namespace std;

int num[10];
int arr[10];
int check[10];
int visit[10];

void dfs(int cnt, int max, int size) {
    if (cnt == max) {
        bool tf = true;
        for (int i = 0; i < max; i++) {
            if (arr[i] != check[i]) {
                tf = false;
            }
        }

        if (tf) return;
        for (int i = 0; i < max; i++) {
            cout << arr[i] << " ";
            check[i] = arr[i];
        }
        cout << "\n";
        return;
    }

    int p = 0;
    for (int i = 0; i < size; i++) {
        if(visit[i]) continue;
        if(num[i] == p) continue;
        arr[cnt] = num[i];
        p = num[i];
        visit[i] = true;
        dfs(cnt + 1, max, size);
        visit[i] = false;
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; i++)
        cin >> num[i];
    sort(num, num + m);

    dfs(0, n, m);
    return 0;
}