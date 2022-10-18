#include <iostream>
#include <queue>

using namespace std;
queue <int> que;
queue <pair<int, int>> bfs;

int h, w;
int map[26][26];
int count[26][26];
int newx, newy;

int x_[4] = {1, 0, -1, 0};
int y_[4] = {0, 1, 0, -1};

int x2_[4] = {2, 0, -2, 0};
int y2_[4] = {0, 2, 0, -2};

void startbfs(int stx, int sty) {
	count[stx][sty] = 1;
	bfs.push({stx, sty});

	while(!bfs.empty()) {
		int oldx, oldy;
		oldx = bfs.front().first;
		oldy = bfs.front().second;
		bfs.pop();
		
		for(int i = 0; i < 4; i++) {
			int newx, newy;
			newx = oldx + x2_[i];
			newy = oldy + y2_[i];

			if(newx < 0 || newx >= h || newy < 0 || newy >= w) continue;
			if(map[(oldx + newx) / 2][(oldy + newy) / 2] == 0) continue;
			if(map[newx][newy] == 0) continue;
			if(count[(oldx + newx) / 2][(oldy + newy) / 2] == 1) continue;
			if(count[newx][newy] == 1) continue;

			que.push(i);
			count[(oldx + newx) / 2][(oldy + newy) / 2] = 1;
			count[newx][newy] = 1;
			bfs.push({newx, newy});
		}
	}
}

int main() {
    cin >> h >> w;
    for(int i = 0; i < h; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < w; j++) {
			if(str[j] == '#') map[i][j] = str[j] - '#' + 1;
			else map[i][j] = str[j] - '.';
		}
    }
	
	int flag = 0;
	int startx, starty;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			int nowx, nowy;
			nowx = i;
			nowy = j;
			if(map[nowx][nowy] == 0) continue;
			for(int k = 0; k < 4; k++) {
				newx = nowx + x_[k];
				newy = nowy + y_[k];
				if(newx < 0 || newx >= h || newy < 0 || newy >= w) continue;
				if(map[newx][newy] == 1 && flag == 1) flag = -1;
				if(map[newx][newy] == 1 && flag == 0) flag = 1;
			}

			if(flag == 1) {
				startx = nowx;
				starty = nowy;
				break;
			}
		}
		if(flag == 1) break;
	}
	cout << startx + 1 << ' ' << starty + 1 << '\n';

	startbfs(startx, starty);
	int flag2 = 0;
	while(!que.empty()) {
		int front, prev;
		if(flag2 == 0) prev = -1;
		front = que.front();
		if(flag2 == 0) {
			if(front == 0) cout << 'v' << '\n';
			else if(front == 1) cout << '>' << '\n';
			else if(front == 2) cout << '^' << '\n';
			else if(front == 3) cout << '<' << '\n';

			flag2 = 1;
			cout << 'A';
		}

		que.pop();
		if(prev != -1) {
			if(front - prev == -1 || front - prev == 3) cout << 'R';
			else if(front - prev == 1 || front - prev == -3) cout << 'L';
			cout << 'A';
		}

		prev = front;
	}

	return 0;
}