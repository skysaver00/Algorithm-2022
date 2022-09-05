#include <vector>
#include <stdio.h>

using namespace std;

bool check[101];
vector<int> graph[101];

void startDFS(int i) {
    if(check[i]) return;
    check[i] = true;

    for(int a = 0; a < graph[i].size(); a++) {
        int y = graph[i][a];
        startDFS(y);
    }
}

int main() {
    int T;
    scanf("%d", &T);

    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int cnt = 0;
    startDFS(1);
    for (int i = 1; i <= T; i++) {
        if (check[i]) cnt++;
    }

    printf("%d\n", cnt - 1);
    return 0;
}