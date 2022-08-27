#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector <int> node[20005];
queue <int> que;
int check[20005];
int state;

bool startbfs(bool val, int x) {
    if(check[x] != 0) return val;
    else {
        state = 1;
        check[x] = state;
        que.push(x);
    }

    bool flag = false;
    while(!que.empty()) {
        int top = que.front();
        int len = node[top].size();

        for(int i = 0; i < len; i++) {
            state = check[top];
            if(state == 1) state = 2;
            else state = 1;
            //cout << '\n';

            if(check[node[top][i]] != 0) {
                //cout << top << ' ' << node[top][i] << ' ' << state << ' ' << check[node[top][i]] << '\n';
                if(check[node[top][i]] == state) continue;
                else {
                    flag = true;
                    break;
                }
            }
            else {
                check[node[top][i]] = state;
                que.push(node[top][i]);
            }
            //cout << "Value is: ";
            //for(int j = 1; j <= 4; j++) cout << check[j] << ' ';
            //cout << '\n';
        }

        if(flag) break;
        que.pop();
    }
    if(flag) return false;
    else return true;
}

int main() {
    int k;
    cin >> k;
    while(k--) {
        int v, e;
        cin >> v >> e;
        for(int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            node[u].push_back(v);
            node[v].push_back(u);
        }

        bool ans = false;
        for(int i = 1; i <= v; i++) ans = startbfs(ans, i);  
        if(ans) cout << "YES" << "\n";
        else cout << "NO" << "\n";
        for(int i = 1; i <= v + 1; i++) node[i].clear();
        fill_n(check, v + 1, 0);
        while(!que.empty()) que.pop();
    }
}