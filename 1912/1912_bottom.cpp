#include <iostream>

using namespace std;
int arr[100001];
int ans[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ans[0] = arr[0];
    int val = ans[0];
    for(int i = 1; i < n; i++) {
        ans[i] = max(ans[i - 1] + arr[i], arr[i]);
        if(val < ans[i]) val = ans[i];
    }

    cout << val;
    return 0;
}