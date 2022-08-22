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
    val[0] = 0;
    val[1] = 1;
    val[2] = 2;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            if(val[j] == 0) {
                if(arr[i][1] < arr[i][2]) {
                    brr[i][j] = brr[i - 1][j] + arr[i][1];
                    val[j] = 1;
                } else {
                    brr[i][j] = brr[i - 1][j] + arr[i][2];
                    val[j] = 2;
                }
            } else if(val[j] == 1) {
                if(arr[i][0] < arr[i][2]) {
                    brr[i][j] = brr[i - 1][j] + arr[i][0];
                    val[j] = 0;
                } else {
                    brr[i][j] = brr[i - 1][j] + arr[i][2];
                    val[j] = 2;
                }
            } else {
                if(arr[i][0] < arr[i][1]) {
                    brr[i][j] = brr[i - 1][j] + arr[i][0];
                    val[j] = 0;
                } else {
                    brr[i][j] = brr[i - 1][j] + arr[i][1];
                    val[j] = 1;
                }
            }
            cout << brr[i][j] << ' ';
        }cout << '\n';
    }
    int minimum = brr[n - 1][0];
    if(minimum > brr[n - 1][1]) minimum = brr[n - 1][1];
    if(minimum > brr[n - 1][2]) minimum = brr[n - 1][2];
    cout << minimum;
}