#include <iostream>
#include <vector>

using namespace std;
vector <int> vec[2001];
bool check[2001];
bool flag = false;

void dfs(int x, int index) {
    if(flag == true) return;
    if(index == 4) {
        cout << "1\n";
        exit(0);
    }

    check[x] = true;
    int len = vec[x].size();
    for(int i = 0; i < len; i++) {
        if(!check[vec[x][i]]) dfs(vec[x][i], index + 1);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for(int i = 0; i < n; i++) {
        dfs(i, 0);
        fill_n(check, 2000, 0);
    }
    cout << "\n";
}