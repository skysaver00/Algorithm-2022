#include <iostream>
#include <vector>

using namespace std;
int room[10][10];
int watched[10][10];
vector <pair<int, int>> cameraloc[10];

int main() {
    int n, m;
    cin >> n >> m;
    int camera = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> room[i][j];
            watched[i][j] = room[i][j];
            if(room[i][j] != 0 || room[i][j] != 6) camera++;
        }
    }


}