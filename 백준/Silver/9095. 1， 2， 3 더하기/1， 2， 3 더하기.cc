#include <stdio.h>

int main() {
	int t, Sum[10];

	Sum[0] = 1, Sum[1] = 2, Sum[2] = 4;
	for (int i = 3; i < 10; i++) {
		Sum[i] = Sum[i - 1] + Sum[i - 2] + Sum[i - 3];
	}

	scanf("%d", &t);
	while (t--) {
		int s;
		scanf("%d", &s);
		printf("%d\n", Sum[s - 1]);
	}

	return 0;
}