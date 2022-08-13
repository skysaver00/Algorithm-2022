#include <iostream>
#include <vector>

using namespace std;
vector<int> ans[501];
vector<int> vec[501];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            int val;
            cin >> val;
            vec[i].push_back(val);
        }
    }
    ans[0].push_back(vec[0][0]);
    for(int i = 1; i < n; i++) {
        ans[i].push_back(ans[i - 1][0] + vec[i][0]);
        for(int j = 1; j < i; j++) ans[i].push_back(max(ans[i - 1][j - 1], ans[i - 1][j]) + vec[i][j]);
        ans[i].push_back(ans[i - 1][i - 1] + vec[i][i]);
    }
    int val = 0;
    for(int i = 0; i < n; i++) val = max(val, ans[n - 1][i]);
    cout << val;
}