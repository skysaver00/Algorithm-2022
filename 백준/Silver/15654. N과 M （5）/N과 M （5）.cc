#include <stdio.h>
#include <algorithm>
using namespace std;

int num[50];
int res[50];
bool visit[50];

void solve(int cnt, int max, int size) {
    if(cnt == max) {
        for(int i = 0; i < max; i++) {
            printf("%d ", res[i]);
        }printf("\n");
        return;
    }

    for(int i = 0; i < size; i++) {
        if(visit[i]) continue;
        res[cnt] = num[i];
        visit[i] = true;
        solve(cnt + 1, max, size);
        visit[i] = false;
    }
}

int main() {
    int n, m; scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    sort(num, num + n);
    solve(0, m, n);

    return 0;
}