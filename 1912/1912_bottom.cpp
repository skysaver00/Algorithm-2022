#include <iostream>

using namespace std;
int ans[100001];
int arr[100001];

int getmax(int x, int y) {
    if(x > y) return x;
    else return y;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        ans[i] = arr[i];
    }

    int max = ans[0];
    for(int i = 1; i < n; i++) {
        ans[i] = getmax(arr[i], ans[i - 1] + arr[i]);
        if(max < ans[i]) max = ans[i];
    }
    cout << max;
}