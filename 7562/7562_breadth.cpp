#include <iostream>
#include <queue>

using namespace std;
int axis[301][301];
int check[301][301];
queue <pair<int, int>> que;
queue <int> val;

int addx[4] = {1, 0, -1, 0};
int addy[4] = {0, 1, 0, -1};

int l;
int stx, sty;
int enx, eny;

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> l;
        cin >> stx >> sty;
        cin >> enx >> eny;
    }
}