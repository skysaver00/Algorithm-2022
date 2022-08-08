#include <stdio.h>
long long num[1001];

int fibo(int n);

int main() {
	num[0] = 1;
	num[1] = 1;
	int t;
	scanf("%d", &t);

	for (int i = 2; i <= t; i++) {
		num[i] = (num[i - 1] + num[i - 2]);
	}

	printf("%lld\n", num[t - 1]);
	return 0;
}

