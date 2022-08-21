#include <cstdio>

int res[10];
int visit[10];

void combination(int idx, int cnt, int max, int size) {
    if(cnt == size) {
        for(int i = 0; i < max; i++) {
            if(visit[i]) printf("%d ", res[i]);
        }printf("\n");
        return;
    }

    for(int i = idx; i < max; i++) {
        if(visit[i]) continue;
        visit[i] = true;
        combination(i, cnt + 1, max, size);
        visit[i] = false;
    }
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) res[i] = i + 1;

    combination(0, 0, n, m);
    return 0;
}