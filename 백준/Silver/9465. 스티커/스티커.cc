#include <iostream>

using namespace std;
long long ans[100001][3];
long long arr[100001][2];

long long getmax(long long i, long long j, long long k) {
    if(i > j) {
        if(i > k) return i;
        else return k;
    } else {
        if(j > k) return j;
        else return k;
    }
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        for(int j = 0; j < 2; j++) {
            for(int k = 1; k <= n; k++) {
                cin >> arr[k][j];
            }
        }
        ans[0][0] = ans[0][1] = ans[0][2] = 0;
        for(int j = 1; j <= n; j++) {
            ans[j][0] = getmax(ans[j - 1][0], ans[j - 1][1], ans[j - 1][2]);
            ans[j][1] = max(ans[j - 1][0], ans[j - 1][2]) + arr[j][0];
            ans[j][2] = max(ans[j - 1][0], ans[j - 1][1]) + arr[j][1];
        }
        cout << getmax(ans[n][0], ans[n][1], ans[n][2]) << "\n";
        for(int j = 1; j <= n; j++) {
            for(int k = 0; k <= 2; k++) {
                arr[j][k] = 0;
            }
        }
    }
}