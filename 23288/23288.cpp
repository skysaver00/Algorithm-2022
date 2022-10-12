#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n, m, k;
int arr[21][21];
int sum[21][21];
bool cnt[21][21];

queue < pair<int, int> > que;

int x_[4] = {1, 0, -1, 0};
int y_[4] = {0, 1, 0, -1};

int dice[4][3] = {{2, 0, 0}, {4, 1, 3}, {5, 0, 0}, {6, 0, 0}};
pair<int, int> loc = {0, 0};
int mx[4] = {0, 1, 0, -1};
int my[4] = {1, 0, -1, 0};
int point = 0;

void east() {
    swap(dice[1][0], dice[1][1]);
    swap(dice[1][0], dice[1][2]);
    swap(dice[1][0], dice[3][0]);
}

void south() {
    swap(dice[1][1], dice[2][0]);
    swap(dice[1][1], dice[3][0]);
    swap(dice[1][1], dice[0][0]);
}

void west() {
    swap(dice[1][0], dice[3][0]);
    swap(dice[1][0], dice[1][2]);
    swap(dice[1][0], dice[1][1]);
}

void north() {
    swap(dice[1][1], dice[0][0]);
    swap(dice[1][1], dice[3][0]);
    swap(dice[1][1], dice[2][0]);
}

int startbfs(int i, int j) {
    int val = arr[i][j];
    int sum2 = 1;
    cnt[i][j] = true;
    que.push({i, j});

    while(!que.empty()) {
        int oldx = que.front().first;
        int oldy = que.front().second;
        que.pop();

        for(int i = 0; i < 4; i++) {
            int newx = oldx + x_[i];
            int newy = oldy + y_[i];

            if(newx < 0 || newx >= n || newy < 0 || newy >= m) continue;
            if(cnt[newx][newy]) continue;
            if(val != arr[newx][newy]) continue;

            sum2++;
            que.push({newx, newy});
            cnt[newx][newy] = true;
        }
    }

    return val * sum2;
}

int main() {
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            sum[i][j] = startbfs(i, j);
            for(int ii = 0; ii < n; ii++) {
                for(int jj = 0; jj < m; jj++) {
                    cnt[ii][jj] = 0;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < k; i++) {
        if(loc.first + mx[point] < 0 || loc.first + mx[point] >= n || loc.second + my[point] < 0 || loc.second + my[point] >= m) {
            point = (point + 2) % 4;
        }

        loc.first += mx[point];
        loc.second += my[point];
        if(point == 0) east();
        if(point == 1) south();
        if(point == 2) west();
        if(point == 3) north();

        ans += sum[loc.first][loc.second];
        
        if(dice[3][0] > arr[loc.first][loc.second]) {
            point++;
            if(point > 3) point %= 4;
        } else if(dice[3][0] < arr[loc.first][loc.second]) {
            point--;
            if(point < 0) point = 3;
        } else {}
    }

    cout << ans << '\n';
    return 0;
}