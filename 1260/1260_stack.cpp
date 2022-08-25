#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
vector <int> node[1005];
bool visited[1005];
queue <int> que;
stack <int> stk;

void startstk(int n) {
    stk.push(n);
    visited[n] = true;
    cout << n << ' ';

    while(!stk.empty()) {
        int top = stk.top();
        int len = node[top].size();
        bool flag = true;
        for(int i = 0; i < len; i++) {
            if(visited[node[top][i]]) continue;
            else {
                flag = false;
                cout << node[top][i] << ' ';
                visited[node[top][i]] = true;
                stk.push(node[top][i]);
                break;
            }
        }
        if(flag) stk.pop();
    }
}

void startque(int n) {
    que.push(n);
    visited[n] = true;
    cout << n << ' ';
    
    while(!que.empty()) {
        int top = que.front();
        int len = node[top].size();
        for(int i = 0; i < len; i++) {
            if(!visited[node[top][i]]) {
                cout << node[top][i] << ' ';
                que.push(node[top][i]);
                visited[node[top][i]] = true;
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
    cout << "\n";
    fill_n(visited, 1001, false);
    startque(start);
    return 0;
}