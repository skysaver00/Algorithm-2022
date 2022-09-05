#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int check[102];
int n, m;
vector <pair<int, int>> ladde;
vector <pair<int, int>> snake;
queue <int> que;

void startbfs(int start) {
    check[start] = 1;
    que.push(start);

    while(!que.empty()) {
        int top = que.front();
        for(int i = 1; i <= 6; i++) {
            int next = top + i;
            que.push(next);
            if(check[next] > 0) continue;
            else check[next] = check[top] + 1;
        }

        for(int i = 0; i < n; i++) {
            
        }

        for(int j = 0; j < m; j++) {

        }
        
        que.pop();
    }
}

int main() {
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