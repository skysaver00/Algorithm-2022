#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector <int> node[1001];
queue <int> que;
bool check[1001];
int ans;

void go(int x) {
    if(check[x]) return;
    else {
        check[x] = true;
        ans++;
        que.push(x);
    }

    while(!que.empty()) {
        int top = que.front();
        int len = node[top].size();

        for(int i = 0; i < len; i++) {
            if(check[node[top][i]]) continue;
            else {
                check[node[top][i]] = true;
                que.push(node[top][i]);
            }
        }
        
        que.pop();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) go(i);
    cout << ans;
}