#include <iostream>
#include <algorithm>

using namespace std;
int arr[10];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    int val = 1;
    for(int i = n; i > 0; i--) val *= i;

    int maximum = 0;
    for(int j = 1; j < n; j++) maximum += abs(arr[j - 1] - arr[j]);
    next_permutation(arr, arr + n);

    for(int i = 0; i < val; i++) {
        bool flag = false;
        for(int j = 1; j < n; j++) if(arr[j - 1] > arr[j]) flag = true;
        if(!flag) break;

        int ans = 0;
        for(int j = 1; j < n; j++) ans += abs(arr[j - 1] - arr[j]);
        if(maximum < ans) maximum = ans;
        next_permutation(arr, arr + n);
    }
    cout << maximum;
}