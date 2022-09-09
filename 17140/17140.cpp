#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <pair<int, int>> vec;
int arr[101][101];

int main() {
    int r, c, k;
    cin >> r >> c >> k;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    int down, right;
    down = right = 3;
    int ans = 0;
    while(1) {
        if(arr[r - 1][c - 1] == k) {
            cout << ans;
            return 0;
        }

        if(right >= down) {
            int tempright = 0;
            for(int i = 0; i < down; i++) {
                for(int j = 0; j < right; j++) {
                    bool flag = false;
                    int sz = vec.size();
                    for(int k = 0; k < sz; k++) {
                        if(vec[k].second == arr[i][j]) {
                            flag = true;
                            vec[k].first++;
                            break;
                        }
                    }
                    if(!flag) {
                        if(arr[i][j] == 0) continue;
                        vec.push_back(make_pair(1, arr[i][j]));
                    }
                }
                sort(vec.begin(), vec.end());
                int sz = vec.size();
                int t = 0;
                for(int j = 0; j < sz; j++) {
                    if(t == 100) break;
                    arr[i][t] = vec[j].second;
                    t++;
                    arr[i][t] = vec[j].first;
                    t++;
                }
                if(t > tempright) tempright = t;
                vec.clear();
            }
            if(right < tempright) right = tempright;
        } else {
            int tempdown = 0;
            for(int i = 0; i < right; i++) {
                for(int j = 0; j < down; j++) {
                    bool flag = false;
                    int sz = vec.size();
                    for(int k = 0; k < sz; k++) {
                        if(vec[k].second == arr[j][i]) {
                            flag = true;
                            vec[k].first++;
                            break;
                        }
                    }   
                    if(!flag) {
                        if(arr[i][j] == 0) continue;
                        vec.push_back(make_pair(1, arr[i][j]));
                    }
                }
                sort(vec.begin(), vec.end());
                int sz = vec.size();
                int t = 0;
                for(int j = 0; j < sz; j++) {
                    if(t == 100) break;
                    arr[t][i] = vec[j].second;
                    t++;
                    arr[t][i] = vec[j].first;
                    t++;
                }
                if(t > tempdown) tempdown = t;
                vec.clear();
                cout << '\n';
            }
            cout << down << ' ' << tempdown << '\n';
            if(down < tempdown) down = tempdown;
        }
        for(int i = 0; i < down; i++) {
            for(int j = 0; j < right; j++) cout << arr[i][j] << ' ';
            cout << '\n';
        }cout << '\n';
    }
}