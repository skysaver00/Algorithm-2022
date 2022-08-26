#include <stdio.h>
#include <algorithm>
using namespace std;

char arr[30][30];
int dn = 0;

int visit[30][30];

int size[630];
int p = 0;

int n;

void dfs(int y, int x) {
	if (visit[y][x] == 1) {
		return;
	}
	else {
		visit[y][x] = 1;
		size[dn]++;
		int dx[4] = {1, -1, 0, 0};
		int dy[4] = {0, 0, 1, -1};
		for (int k = 0; k < 4; k++) {
			int ax = x + dx[k];
			int ay = y + dy[k];
			if (0 <= ax && ax < n && 0 <= ay && ay < n) {
				if (arr[ay][ax] == '1' && visit[ay][ax] == 0)  {
					dfs(ay, ax);
				}
			}
		}
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
	}

	for (int i = 0; i < 630; i++) size[i] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '1') {
				if (visit[i][j] == 0) {
					dfs(i, j);
					dn++;
				}
			}
		}
	}
	sort(size, size + dn);
	printf("%d\n", dn);
	for (int i = 0; i < dn; i++) printf("%d\n", size[i]);


	return 0;
}
