#include <iostream>

using namespace std;
long long arr[1000009];

int main() {
    int t, n;
    cin >> t;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    for(int i = 4; i <= 1000000; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
        arr[i] %= 1000000009;
    }

    for(int i = 0; i < t; i++) {
        cin >> n;
        cout << arr[n] << '\n';
    }
}