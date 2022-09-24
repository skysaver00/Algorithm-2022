#include <iostream>
#include <vector>

using namespace std;
vector <pair<int, int>> vec;
int arr[52][52];

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    vec.push_back({n, 1});
    vec.push_back({n, 2});
    vec.push_back({n - 1, 1});
    vec.push_back({n - 1, 2});
}