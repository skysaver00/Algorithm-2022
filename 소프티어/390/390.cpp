#include <iostream>

using namespace std;
int arr[3001];
int dp[3001];

int main() {
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}

	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++) if(ans < dp[i]) ans = dp[i];
	cout << ans << '\n';
}