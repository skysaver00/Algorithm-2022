#include <stdio.h>

void dfs(int n, int pos, int cnt);
int senario[8];
int dwarfs[9];
int sum = 0, temp, flag = 0;

void dfs(int n, int pos, int cnt) {
	if(flag == 1) {
		return;
	}

	if(cnt == 7) {
		for(int i = 0; i < 7; i++) {
			sum += senario[i];
		}
		if(sum == 100) {
			for(int i = 0; i < 6; i++) {
				for(int j = 0; j < 6 - i; j++) {
					if(senario[j] > senario[j + 1]) {
						temp = senario[j];
						senario[j] = senario[j + 1];
						senario[j + 1] = temp;
					}
				}
			}
			for(int i = 0; i < 7; i++) {
				printf("%d\n", senario[i]);
			}
			flag = 1;
			return;
		}
		else {
			sum = 0;
			return;
		}
	}

	if(pos >= n - 1) {
		return;
	}

	for(int i = pos + 1; i < n; i++) {
		senario[cnt] = dwarfs[i];

		dfs(n, i, cnt + 1);
	}
}

int main () {
	for(int i = 0; i < 9; i++) {
		scanf("%d", &dwarfs[i]);
	}

	dfs(9, -1, 0);

	return 0;
}
