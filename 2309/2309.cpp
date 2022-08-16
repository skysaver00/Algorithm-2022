#include <iostream>
#include <algorithm>

using namespace std;
int maxi = 0;
int arr[9];
int ex[2];

void exclude(int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int t = maxi;
            t -= arr[i];
            t -= arr[j];
            if(t == 100) {
                ex[0] = i;
                ex[1] = j;
                return;
            }
        }
    }
}

int main() {
    for(int i = 0; i < 9; i++) {
        cin >> arr[i];
        maxi += arr[i];
    }
    sort(arr, arr + 9);

    exclude(9);
    for(int i = 0; i < 9; i++) {
        if(i == ex[0] || i == ex[1]) continue;
        cout << arr[i] << "\n";
    }
}