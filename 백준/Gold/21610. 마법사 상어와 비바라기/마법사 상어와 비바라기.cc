#include <iostream>
#include <vector>

using namespace std;
vector <pair<int, int>> vec;
vector <pair<int, int>> vec_cp;
int arr[52][52];

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    vec.push_back({n, 1});
    vec.push_back({n, 2});
    vec.push_back({n - 1, 1});
    vec.push_back({n - 1, 2});

    for(int k = 0; k < m; k++) {
        int d, s;
        cin >> d >> s;

        int sz = vec.size();
        if(d == 1) {
            for(int i = 0; i < sz; i++) {
                if(vec[i].second - (s % n) <= 0) {
                    vec[i].second += n;
                    vec[i].second -= (s % n);
                    if(s % n == 0) vec[i].second -= n;
                } else vec[i].second -= (s % n);
            }
        }
        if(d == 2) {
            for(int i = 0; i < sz; i++) {
                if(vec[i].second - (s % n) <= 0) {
                    vec[i].second += n;
                    vec[i].second -= (s % n);
                    if(s % n == 0) vec[i].second -= n;
                } else vec[i].second -= (s % n);
                if(vec[i].first - (s % n) <= 0) {
                    vec[i].first += n;
                    vec[i].first -= (s % n);
                    if(s % n == 0) vec[i].first -= n;
                } else vec[i].first -= (s % n);
            }
        }
        if(d == 3) {
            for(int i = 0; i < sz; i++) {
                if(vec[i].first - (s % n) <= 0) {
                    vec[i].first += n;
                    vec[i].first -= (s % n);
                } else vec[i].first -= (s % n);
            }
        }
        if(d == 4) {
            for(int i = 0; i < sz; i++) {
                if(vec[i].second + (s % n) > n) {
                    vec[i].second -= n;
                    vec[i].second += (s % n);
                } else vec[i].second += (s % n);
                if(vec[i].first - (s % n) <= 0) {
                    vec[i].first += n;
                    vec[i].first -= (s % n);
                } else vec[i].first -= (s % n);
            }
        }
        if(d == 5) {
            for(int i = 0; i < sz; i++) {
                if(vec[i].second + (s % n) > n) {
                    vec[i].second -= n;
                    vec[i].second += (s % n);
                } else vec[i].second += (s % n);
            }
        }
        if(d == 6) {
            for(int i = 0; i < sz; i++) {
                if(vec[i].second + (s % n) > n) {
                    vec[i].second -= n;
                    vec[i].second += (s % n);
                } else vec[i].second += (s % n);
                if(vec[i].first + (s % n) > n) {
                    vec[i].first -= n;
                    vec[i].first += (s % n);
                } else vec[i].first += (s % n);
            }
        }
        if(d == 7) {
            for(int i = 0; i < sz; i++) {
                if(vec[i].first + (s % n) > n) {
                    vec[i].first -= n;
                    vec[i].first += (s % n);
                } else vec[i].first += (s % n);
            }
        }
        if(d == 8) {
            for(int i = 0; i < sz; i++) {
                if(vec[i].second - (s % n) <= 0) {
                    vec[i].second += n;
                    vec[i].second -= (s % n);
                } else vec[i].second -= (s % n);
                if(vec[i].first + (s % n) > n) {
                    vec[i].first -= n;
                    vec[i].first += (s % n);
                } else vec[i].first += (s % n);
            }
        }

        for(int i = 0; i < sz; i++) arr[vec[i].first][vec[i].second]++;

        for(int i = 0; i < sz; i++) {
            if(arr[vec[i].first - 1][vec[i].second - 1] != 0) arr[vec[i].first][vec[i].second]++;
            if(arr[vec[i].first - 1][vec[i].second + 1] != 0) arr[vec[i].first][vec[i].second]++;
            if(arr[vec[i].first + 1][vec[i].second - 1] != 0) arr[vec[i].first][vec[i].second]++;
            if(arr[vec[i].first + 1][vec[i].second + 1] != 0) arr[vec[i].first][vec[i].second]++;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                int flag = 0;
                for(int l = 0; l < sz; l++) {
                    if(i == vec[l].first && j == vec[l].second) {
                        flag = 1;
                        break;
                    }
                }
                if(arr[i][j] >= 2 && flag == 0) {
                    arr[i][j] -= 2;
                    vec_cp.push_back({i, j});
                }
            }
        }

        vec.clear();
        vec = vec_cp;
        vec_cp.clear();
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            ans += arr[i][j];
        }
    }
    cout << ans << '\n';
    return 0;
}