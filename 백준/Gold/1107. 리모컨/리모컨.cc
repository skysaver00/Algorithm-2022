#include <cstdio>
#include <cmath>
int button[11];
int live[11];
bool chaCh[1000001];
int num = 0;
int cha;
int ans;
int c = 0;
//int minLimit, maxLimit;

int min(int i, int j) {
    return i < j ? i : j;
}

void permutation(int cnt, int max, int size) {
    if(max <= 0 || max >= 7) return;
    if(cnt == max) {
        if(chaCh[num]) return;
        ans = min(ans, cnt + abs(num - cha));
        chaCh[num] = true;
        return;
    }

    for(int i = 0; i < size; i++) {
        num *= 10;
        num += live[i];
        //printf("%d, %d, %d\n", num, i, live[i]);
        permutation(cnt + 1, max, size);
        num /= 10;
    }
}

int solve(int cha) {
    int mir = cha;
    int check = 0;
    if(mir == 0) check++;
    while(mir != 0) {
        mir /= 10;
        check++;
    }
    permutation(0, check - 1, c);
    permutation(0, check, c);
    permutation(0, check + 1, c);
    return 0;
}

int main() {
    scanf("%d", &cha);
    ans = abs(cha - 100);
    int m; scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        int but; scanf("%d", &but);
        button[but] = 1;
    }

    for(int i = 0; i < 10; i++) {
        if(button[i] == 0) {
            live[c] = i;
            c++;
        }
    }
    solve(cha);
    printf("%d\n", ans);
    return 0;
}