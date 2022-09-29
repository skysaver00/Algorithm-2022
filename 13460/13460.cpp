#include <iostream>
#include <queue>

using namespace std;

queue <pair<int, pair<int, int>>> que;
char arr[12][12];

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            arr[i][j] = c;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << arr[i][j] << ' ';
        }cout << '\n';
    }

}