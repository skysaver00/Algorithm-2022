#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> depth[1001];
queue<int> breadth[1001];
int check[1001];

void dfs(int v, vector<int> depth[], int check[]) {
	check[v] = true;
	printf("%d ", v);

	for (int i = 0; i < depth[v].size(); i++) {
		int next = depth[v][i];
		if (check[next] == 0) dfs(next, depth, check);
	}
}

void bfs(int v, vector<int> depth[], int check[]) {
	breadth->push(v);
	check[v] = true;

	while (breadth->empty() != true) {
		int num = breadth->front();
		printf("%d ", num);
		breadth->pop();

		for (int i = 0; i < depth[num].size(); i++) {
			if (check[depth[num][i]] == 0) {
				breadth->push(depth[num][i]);
				check[depth[num][i]] = 1;
			}
		}
	}
}


int main() {
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);

	for (int i = 0; i < m; i++) {
		int up, down;
		scanf("%d %d", &up, &down);

		depth[up].push_back(down);
		depth[down].push_back(up);
	}

	for (int i = 1; i <= n; i++) sort(depth[i].begin(), depth[i].end());
	
	dfs(v, depth, check);
	printf("\n");

	for (int i = 0; i <= 1000; i++) check[i] = 0;
	bfs(v, depth, check);
}