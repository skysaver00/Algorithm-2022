#include <stdio.h>
#include <stdlib.h>

using namespace std;
int N, M;
int room[51][51];
int cleaned;

int x[4] = {-1, 0, 1, 0};
int y[4] = {0, 1, 0, -1};

void dfs(int r, int c, int d) {
    if(room[r][c] == 0) {
        cleaned++;
        room[r][c] = 2;
    }

    for(int i = 0; i <= 3; i++) {
        int nd = (d + 3 - i) % 4;
        int nX = r + x[nd];
        int nY = c + y[nd];

        if (nX < 0 || nY < 0 || nX >= N || nY >= M) {
            continue;
        }

        if (room[nX][nY] == 0) {
            dfs(nX, nY, nd);
        }
    }
    int nX = r + x[(d + 2) % 4];
    int nY = c + y[(d + 2) % 4];

    if(room[nX][nY] == 1) {
        printf("%d\n", cleaned);
        exit(0);
    }
    dfs(nX, nY, d);
}

int main() {
    scanf("%d %d", &N, &M);

    int r, c, d;
    scanf("%d %d %d", &r, &c, &d);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &room[i][j]);
        }
    }

    dfs(r, c, d);
    return 0;
}