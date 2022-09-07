#include <iostream>

using namespace std;
int dice[4][3];
int room[21][21];

int main() {
    int n, m, x, y, k;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }
    int nowx, nowy;
    nowx = x;
    nowy = y;
    int up, down;
    up = 0, down = 2;
    for(int i = 0; i < k; i++) {
        int order;
        cin >> order;
        if(order == 3 || order == 4) {
            
        }
    }


    return 0;
}