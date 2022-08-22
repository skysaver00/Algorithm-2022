#include <iostream>

using namespace std;
int arr[100001][3];

int main() {
    int n;
    cin >> n;
    arr[0][0] = arr[0][1] = arr[0][2] = 1;
    for(int i = 1; i < n; i++) {
        arr[i][0] = (arr[i - 1][1] + arr[i - 1][2]) % 9901;
        arr[i][1] = (arr[i - 1][0] + arr[i - 1][2]) % 9901;
        arr[i][2] = (arr[i - 1][0] + arr[i - 1][1] + arr[i - 1][2]) % 9901;
    }
    cout << (arr[n - 1][0] + arr[n - 1][1] + arr[n - 1][2]) % 9901;
}