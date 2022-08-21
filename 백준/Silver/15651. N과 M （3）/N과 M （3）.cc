#include <cstdio>
int number[50];
int res[50];
bool visit[50];
void dfs(int cnt, int max, int size) {
    if(cnt == max) {
        for(int i = 0; i < max; i++) printf("%d ", res[i]);
        printf("\n");
        return;
    }

    for(int i = 0; i < size; i++) {
        res[cnt] = number[i];
        dfs(cnt + 1, max, size);
    }
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) number[i] = i + 1;
    dfs(0, m, n);

    return 0;
}