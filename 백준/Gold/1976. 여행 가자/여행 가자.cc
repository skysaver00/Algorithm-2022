#include <stdio.h>
#include <queue>
using namespace std;

bool arr[201][201];
int line[1001];
int check[201];
int n, m;
queue<int> pairQue;

void startBFS(int i) {
    pairQue.push(i);

    while(!pairQue.empty()) {
        int val = pairQue.front();
        pairQue.pop();
        check[val] = true;

        for(int k = 1; k <= n; k++) {
            if(arr[val][k] == 0 || check[k] != 0) continue;
            else {
                pairQue.push(k);
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    scanf("%d", &m);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 0; i < m; i++) scanf("%d", &line[i]);
    /*for(int i = 1; i <= n; i++) {
        startBFS(i);
        for(int j = 1; j <= n; j++) check[j] = 0;
    }*/
    startBFS(line[0]);
    for(int i = 0; i < m; i++) {
        if(check[line[i]] == 0) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}