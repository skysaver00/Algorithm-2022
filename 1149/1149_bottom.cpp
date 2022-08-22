#include <iostream>

using namespace std;
int arr[1000][3];
int brr[1000][3];
int val[3];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    brr[0][0] = arr[0][0];
    brr[0][1] = arr[0][1];
    brr[0][2] = arr[0][2];
    for(int i = 1; i < n; i++) {
        brr[i][0] = min(brr[i - 1][1], brr[i - 1][2]) + arr[i][0];
        brr[i][1] = min(brr[i - 1][0], brr[i - 1][2]) + arr[i][1];
        brr[i][2] = min(brr[i - 1][0], brr[i - 1][1]) + arr[i][2];
    }
    
    int minimum = brr[n - 1][0];
    minimum = min(minimum, brr[n - 1][1]);
    minimum = min(minimum, brr[n - 1][2]);
    cout << minimum;
}