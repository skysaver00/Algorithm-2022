#include <stdio.h>
int n, s;
int arr[15];
int arr2[6];
int count = 0;

void dfs(int x, int start, int ans) {
	if (start == 6) {
		for (int i = 0; i < start; i++) {
			printf("%d ", arr2[i]);
		}
		printf("\n");
		return;
	}

	for (int i = ans; i < x; i++) {
		arr2[start] = arr[i];
		dfs(x, start + 1, i + 1);
	}
}

int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0) { return 0; }

		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		dfs(n, 0, 0);
		printf("\n");
	}

	return 0;
}
