#include <iostream>
#include <algorithm>

using namespace std;
int arr[51];
int party[51][51];
int num[51];
int know[51];

int getParent(int x) {
    if(arr[x] == x) return x;
    return arr[x] = getParent(arr[x]);
}

void unionFind(int x, int y) {
    x = getParent(x);
    y = getParent(y);
    if(x > y) arr[x] = y;
    else arr[y] = x;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) arr[i] = i;

    for(int i = 0; i < k; i++) cin >> know[i];
    sort(know, know + k);

    for(int i = 0; i < m; i++) {
        cin >> num[i];
        for(int j = 0; j < num[i]; j++) cin >> party[i][j];
        sort(party[i], party[i] + num[i]);

        for(int j = 1; j < num[i]; j++) unionFind(party[i][0], party[i][j]);
    }

    for(int i = 0; i < k; i++) know[i] = getParent(know[i]);

    int ans = 0;
    for(int i = 0; i < m; i++) {
        bool flag = false;
        for(int j = 0; j < num[i]; j++) {
            for(int h = 0; h < k; h++) {
                if(getParent(party[i][j]) == know[h]) {
                    flag = true;
                    break;
                }
            }
            if(flag == true) break;
        }
        if(flag) {}
        else ans++;
    }
    cout << ans << '\n';
    return 0;
}