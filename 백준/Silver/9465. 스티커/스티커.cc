#include <iostream>

using namespace std;
int arr[2][100001];
int brr[3][100001];

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) cin >> arr[i][j];
        }

        brr[0][0] = arr[0][0];
        brr[1][0] = arr[1][0];
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                if(j == 0) brr[0][i] = max(brr[1][i - 1], brr[2][i - 1]) + arr[0][i];
                if(j == 1) brr[1][i] = max(brr[0][i - 1], brr[2][i - 1]) + arr[1][i];
                if(j == 2) {
                    brr[2][i] = max(brr[0][i - 1], brr[1][i - 1]);
                    brr[2][i] = max(brr[2][i], brr[2][i - 1]);
                }
            }
        }
        int maximum = brr[0][n - 1];
        maximum = max(brr[1][n - 1], maximum);
        maximum = max(brr[2][n - 1], maximum);
        cout << maximum << "\n";
    }
}