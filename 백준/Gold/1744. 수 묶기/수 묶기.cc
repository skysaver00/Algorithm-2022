#include <iostream>
#include <algorithm>

using namespace std;

int arr[51];
int ans[51];
int pos, neg, one;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] > 1) pos++;
        else if(arr[i] < 0) neg++;
        else if(arr[i] == 1) one++;
    }

    sort(arr, arr + n, greater<>());

    int now = 0;
    for(int i = 0; i < pos; i += 2) {
        if(i + 2 > pos) break;
        ans[now] = arr[i] * arr[i + 1];
        now++;
    }
    if(pos % 2 != 0) {
        ans[now] = arr[pos - 1];
        now++;
    }

    for(int i = pos; i < pos + one; i++) {
        ans[now] = 1;
        now++;
    }

    int negk = neg;
    for(int i = n - 1; i >= pos; i -= 2) {
        if(negk - 2 < 0) break;
        negk -= 2;
        ans[now] = arr[i] * arr[i - 1];
        now++;
    }

    if(pos + neg + one == n && neg % 2 != 0) {
        ans[now] = arr[pos + one];
        now++;
    }

    int finalans = 0;
    for(int i = 0; i < now; i++) finalans += ans[i];
    cout << finalans;

    return 0;
}