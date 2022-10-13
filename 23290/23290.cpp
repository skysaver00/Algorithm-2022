#include <iostream>
#include <vector>

using namespace std;
vector <int> vec[4][4];

int main() {
    int p = 1;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {
                vec[i][j].push_back(p);
                p++;
            }
        }
    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            int sz = vec[i][j].size();
            cout << sz << ' ';
            for(int k = 0; k < sz; k++) {
                cout << vec[i][j][k] << ' ';
            }cout << '\n';
        }
    }
}