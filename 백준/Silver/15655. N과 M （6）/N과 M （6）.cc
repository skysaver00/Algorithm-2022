#include <stdio.h>
#include <algorithm>
using namespace std;
int number[50];
int visit[50];

void dfs(int idx, int cnt, int max, int size) {
    if(cnt == max) {
        for(int i = 0; i < size; i++) if(visit[i]) printf("%d ", number[i]);
        printf("\n");
        return;
    }

    for(int i = idx; i < size; i++) {
        if(visit[i]) continue;
        visit[i] = true;
        dfs(i, cnt + 1, max, size);
        visit[i] = false;
    }
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &number[i]);
    sort(number, number + n);

    dfs(0,0, m, n);
    return 0;
}