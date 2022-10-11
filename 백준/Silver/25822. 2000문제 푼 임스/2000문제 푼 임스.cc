#include <iostream>
#include <vector>

using namespace std;
vector <int> no;
int arr[100001];
int dp[100001][3];

int main() {
    double c;
    cin >> c;
    c /= 0.99;
    if(c >= 2.0) c = 2;
    int cc = c;

    int n;
    cin >> n;

    int maxi = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(maxi < arr[i]) maxi = arr[i];
    }

    if(arr[0] == 0) dp[0][0] = 0;
    else dp[0][0] = 1;

    if(dp[0][0] == 0 && c > 0) dp[0][1] = 1;

    for(int i = 1; i < n; i++) {
        if(arr[i] > 0) {
            for(int j = 0; j <= cc; j++) {
                dp[i][j] = dp[i - 1][j] + 1;
            }
        } else {
            for(int j = 1; j <= cc; j++) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }

    int maxday = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= cc; j++) {
            if(maxday < dp[i][j]) maxday = dp[i][j];
        }
    }

    cout << maxday << '\n' << maxi << '\n';
    return 0;
}