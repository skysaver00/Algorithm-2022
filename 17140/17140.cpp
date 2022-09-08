#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <pair<int, int>> vec;
int arr[101][101];

int main() {
    int r, c, k;
    cin >> r >> c >> k;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    int down, right;
    down = right = 1;
    int ans = 0;
    while(1) {
        if(arr[r][c] == k) {
            cout << ans;
            return 0;
        }

        if(right >= down) {
            
        }
    }
}