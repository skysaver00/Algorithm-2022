#include <iostream>
#include <vector>

using namespace std;
vector <pair<int, int>> vec;
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
                if(vec[i].second - s <= 0) {
                    vec[i].second += n;
                    vec[i].second -= (s % n);
                    if(s % n == 0) vec[i].second -= n;
                } else vec[i].second -= s;
            }
        }
        if(d == 2) {
            for(int i = 0; i < sz; i++) {
                if(vec[i].second - s <= 0) {
                    vec[i].second += n;
                    vec[i].second -= (s % n);
                    if(s % n == 0) vec[i].second -= n;
                } else vec[i].second -= s;
                if(vec[i].first - s <= 0) {
                    vec[i].first += n;
                    vec[i].first -= (s % n);
                    if(s % n == 0) vec[i].first -= n;
                } else vec[i].first -= s;
            }
        }
        if(d == 3) {
            for(int i = 0; i < sz; i++) {
                if(vec[i].first - s <= 0) {
                    vec[i].first += n;
                    vec[i].first -= (s % n);
                } else vec[i].first -= s;
            }
        }
        if(d == 4) {
            for(int i = 0; i < sz; i++) {
                if(vec[i].second + s > n) {
                    vec[i].second -= n;
                    vec[i].second += (s % n);
                } else vec[i].second += s;
                if(vec[i].first - s <= 0) {
                    vec[i].first += n;
                    vec[i].first -= (s % n);
                } else vec[i].first -= s;
            }
        }
        if(d == 5) {
            for(int i = 0; i < sz; i++) {
                if(vec[i].second + s > n) {
                    vec[i].second -= n;
                    vec[i].second += (s % n);
                } else vec[i].second += s;
            }
        }
        if(d == 6) {
            for(int i = 0; i < sz; i++) {
                if(vec[i].second + s > n) {
                    vec[i].second -= n;
                    vec[i].second += (s % n);
                } else vec[i].second += s;
                if(vec[i].first + s > n) {
                    vec[i].first -= n;
                    vec[i].first += (s % n);
                } else vec[i].first += s;
            }
        }
        if(d == 7) {
            for(int i = 0; i < sz; i++) {
                if(vec[i].first + s > n) {
                    vec[i].first -= n;
                    vec[i].first += (s % n);
                } else vec[i].first += s;
            }
        }
        if(d == 8) {
            for(int i = 0; i < sz; i++) {
                if(vec[i].second - s <= 0) {
                    vec[i].second += n;
                    vec[i].second -= (s % n);
                } else vec[i].second -= s;
                if(vec[i].first + s > n) {
                    vec[i].first -= n;
                    vec[i].first += (s % n);
                } else vec[i].first += s;
            }
        }

        for(int i = 0; i < sz; i++) {
            cout << vec[i].first << ' ' << vec[i].second << '\n';
        }
    }
}