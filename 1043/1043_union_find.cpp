#include <iostream>
#include <algorithm>

using namespace std;
int arr[51];
int party[51][51];
int know[51];

int getParent(int x) {
    if(arr[x] == x) return x;
    return arr[x] = getParent(arr[x]);
}

void unionFind(int x, int y) {
    x = getParent(x);
    y = getParent(y);
    if(x < y) arr[x] = y;
    else arr[y] = x;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < k; i++) cin >> know[i];
    sort(know, know + k);

    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        for(int j = 0; j < num; j++) cin >> party[i][j];
        sort(party, party + num);

        for(int j = 1; j < num; j++) unionFind(party[i][0], party[i][j]);
    }

    
    for(int i = 0; i < m; i++) {

    }

}