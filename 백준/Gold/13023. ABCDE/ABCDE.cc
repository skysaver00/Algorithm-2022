#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> buddy[2001];
bool check[2001];
int cnt = 0;

void dfs(int now, int cnt) {
    if(check[now]) {
        return;
    }

    if(cnt == 4) {
        cout << "1\n";
        exit(0);
    }

    int sz = buddy[now].size();
    check[now] = true;
    for(int i = 0; i < sz; i++) {
        if(check[buddy[now][i]]) continue;
        dfs(buddy[now][i], cnt + 1);
    }
    check[now] = false;
}

int main() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        buddy[a].push_back(b);
        buddy[b].push_back(a);
    }

    for(int i = 0; i < n; i++) sort(buddy[i].begin(), buddy[i].end());

    for(int i = 0; i <= n; i++) {
        dfs(i, 0);

        for(int j = 0; j <= n; j++) {
            check[j] = false;
        }
    }

    cout << "0\n";
    return 0;
}