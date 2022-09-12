#include <iostream>
#include <queue>

using namespace std;
int arr[101][101];
bool check[101];
int n;
queue <int> que;

bool startbfs(int i, int j) {
    que.push(i);

    while(!que.empty()) {
        int front = que.front();
        if(front == j && check[j]) {
            while(!que.empty()) que.pop();
            return true;
        }
        que.pop();
        for(int i = 0; i < n; i++) {
            if(arr[front][i] == 1 && !check[i]) {
                check[i] = true;
                que.push(i);
            }  
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << startbfs(i, j) << ' ';
            fill_n(check, 100, false);
        }cout << '\n';
    }
}