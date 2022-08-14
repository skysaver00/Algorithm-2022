#include <iostream>

using namespace std;
int ans[1001];
int arr[1001];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    fill_n(ans, 1000, 1);
    int max = 1;
    for(int i = n - 2; i >= 0; i--) {
        for(int j = n - 1; j > i; j--) {
            if(arr[i] > arr[j] && ans[j] + 1 > ans[i]) {
                ans[i] = ans[j] + 1;
                if(max < ans[i]) max = ans[i];
            }
        }
    }
    cout << max;
}