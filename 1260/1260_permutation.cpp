#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
vector <int> node[1001];
bool check[1001];
queue <int> que;

void startstk(int x) {
    if(check[x]) return;
    cout << x << ' ';
    check[x] = true;

    int len = node[x].size();
    for(int i = 0; i < len; i++) {
        startstk(node[x][i]);
    }
}

void startque(int x) {
    cout << x << ' ';
    que.push(x);
    check[x] = true;

    while(!que.empty()) {
        int top = que.front();
        int len = node[top].size();

        for(int i = 0; i < len; i++) {
            if(check[node[top][i]]) continue;
            else {
                cout << node[top][i] << ' ';
                check[node[top][i]] = true;
                que.push(node[top][i]);
            }
        }
        que.pop();
    }
}

int main() {
    int n, m, start;
    cin >> n >> m >> start;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) sort(node[i].begin(), node[i].end());

    startstk(start);
    cout << '\n';
    fill_n(check, 1001, false);
    startque(start);
}