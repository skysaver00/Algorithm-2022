#include <stdio.h>
int arr[11];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int coin = 0;
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	
	int po = n - 1;
	int mul;
	while (1) {
		if (k - arr[po] >= 0) {
			mul = k / arr[po];
			k -= arr[po] * mul;
			coin += mul;
		}
		else {
			po--;
		}

		if (po < 0) break;
	}

	printf("%d\n", coin);
}