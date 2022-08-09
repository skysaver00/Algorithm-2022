#include <iostream>

using namespace std;
int ans[100001];
int arr[100001];
bool check[100001];

int dp(int x) {
    if(x == 0) return arr[0];
    if(check[x] == true) return ans[x];

    int temp = dp(x - 1) + arr[x];
    if(temp >= ans[x]) ans[x] = temp;
    check[x] = true;

    return ans[x];
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        ans[i] = arr[i];
    }

    dp(n);
    int max = arr[1];
    for(int i = 0; i < n; i++) if(max < ans[i]) max = ans[i];
    cout << max;
}