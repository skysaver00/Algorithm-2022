#include <stdio.h>
#include <queue>
using namespace std;

int map[101][101];
int check[101][101];
int row, col;
int point[4][2];

queue<pair<int, int>> qu;

void bfs() {
	
	int x = 0;
	int y = 0;
	check[x][y] = 1;

	qu.push(pair<int, int>(x, y));

	while (qu.empty() == false) {
		y = qu.front().first;
		x = qu.front().second;
		qu.pop();
		
		if (x == row - 1 && y == col - 1) break;

		for (int i = 0; i < 4; i++) {
			int x2 = x + point[i][0];
			int y2 = y + point[i][1];

			if (y2 >= 0 && y2 < row && x2 >= 0 && x2 < col) {
				if (check[y2][x2] == 0 && map[y2][x2] == 1) {
					check[y2][x2] = check[y][x] + 1;
					qu.push(pair<int, int>(y2, x2));
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &row, &col);

	point[0][0] = 1, point[1][0] = -1, point[2][0] = 0, point[3][0] = 0;
	point[0][1] = 0, point[1][1] = 0, point[2][1] = 1, point[3][1] = -1;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	bfs();
	printf("%d\n", check[row - 1][col - 1]);
}
