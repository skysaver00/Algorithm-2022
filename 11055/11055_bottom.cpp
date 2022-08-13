#include <iostream>

using namespace std;
int ans[1001];
int arr[1001];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int max = 0;
    for(int i = 0; i < n; i++) {
        ans[i] = arr[i];
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j] && ans[j] + arr[i] > ans[i]) ans[i] = ans[j] + arr[i];
        }
        if(max < ans[i]) max = ans[i];
    }
    cout << max;
}