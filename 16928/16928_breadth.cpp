#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int check[102];
vector <pair<int, int>> ladde;
vector <pair<int, int>> snake;
queue <int> que;

void startbfs(int start) {
    check[start] = 1;
    que.push(start);

    while(!que.empty()) {
        int top = que.front();
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ladde.push_back(make_pair(x, y));
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        snake.push_back(make_pair(u, v));
    }

    startbfs(0);
    return 0;
}