#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector <int> node[1001];
stack <int> stk;
bool check[1001];
int ans;

void dfs(int x) {
    if(check[x]) return;
    else {
        ans++;
        check[x] = true;
        stk.push(x);
    }

    while(!stk.empty()) {
        int top = stk.top();
        int len = node[top].size();

        bool flag = true;
        for(int i = 0; i < len; i++) {
            if(check[node[top][i]]) continue;
            else {
                flag = false;
                check[node[top][i]] = true;
                stk.push(node[top][i]);
            }
        }
        if(flag) stk.pop();
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

    for(int i = 1; i <= n; i++) dfs(i);
    cout << ans;
}