#include <stdio.h>

int main() {
    int E, S, M;
    scanf("%d %d %d", &E, &S, &M);

    int vE = 1, vS = 1, vM = 1;

    int count = 1;
    while(E != vE || S != vS || M != vM) {
        if(vE == 15) vE = 0;
        if(vS == 28) vS = 0;
        if(vM == 19) vM = 0;

        vE++; vS++; vM++;
        count++;
    }

    printf("%d\n", count);

    return 0;
}