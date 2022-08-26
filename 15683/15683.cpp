#include <iostream>
#include <vector>

using namespace std;
int room[10][10];
int watched[10][10];
vector <pair<int, int>> cameraloc[10];
int cameratype[10];
int looktype[10];
int val;

void go(int index, int n, int m) {
    if(index == m) {
        val++;
        for(int i = 0; i < m; i++) cout << looktype[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++) {
        looktype[index] = i;
        go(index + 1, n, m);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int camera = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> room[i][j];
            watched[i][j] = room[i][j];
            if(room[i][j] != 0 && room[i][j] != 6) {
                cameratype[camera] = room[i][j];
                cameraloc[i].push_back(make_pair(i, j));
                camera++;
            }
        }
    }
    cout << camera << "\n";

    go(0, 4, camera);
    cout << val;
}