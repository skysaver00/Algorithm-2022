#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

bool binary(int start, int end, int value) {
    int mid = (start + end) / 2;

    if(arr[mid] == value) return true;
    else if(arr[mid] > value) {
        return binary(mid + 1, end, value);
    } else {
        return binary(start, mid - 1, value);
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    int m;
    cin >> m;

    for(int i = 0; i < m; i++) {
        int value;
        cin >> value;

        int ans = binary(0, n - 1, value);
    }

    return 0;
}