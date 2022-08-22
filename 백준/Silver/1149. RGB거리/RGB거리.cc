#include <stdio.h>
#define Min(X, Y) (((X) < (Y)) ? (X) : (Y))
int compare3(int a, int b, int c);

int color[1001][3];
int DP[1001][3];
int main()
{
    int i, house;
    scanf("%d", &house);

    for(i = 1; i <= house; i++) {
        scanf("%d %d %d", &color[i][0], &color[i][1], &color[i][2]);
    }

    DP[1][0] = color[1][0], DP[1][1] = color[1][1], DP[1][2] = color[1][2];
    for(i = 2; i <= house; i++) {
        DP[i][0] = Min(DP[i - 1][1], DP[i - 1][2]) + color[i][0];
        DP[i][1] = Min(DP[i - 1][0], DP[i - 1][2]) + color[i][1];
        DP[i][2] = Min(DP[i - 1][0], DP[i - 1][1]) + color[i][2];
    }

    compare3(DP[house][0], DP[house][1], DP[house][2]);

    return 0;
}

int compare3(int a, int b, int c)
{
    int max;
    if(a < b) {
        if(a < c) max = a;
        else max = c;
    }

    else {
        if(b < c) max = b;
        else max = c;
    }

    printf("%d\n", max);
}
