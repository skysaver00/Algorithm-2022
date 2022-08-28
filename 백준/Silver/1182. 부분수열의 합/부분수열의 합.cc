#include <iostream>

using namespace std;

int n, s;
int arr[21];
int number[21];
int val;
int ans;
bool flag = false;

void go(int index, int n, int m) {
    if(index == m) {
        if(!flag) {
            flag = true;
            return;
        }
        val = 0;
        for(int i = 0; i < m; i++) if(arr[i] == 1) val += number[i];
        if(val == s) ans++;
        return;
    }

    for(int i = 0; i < 2; i++) {
        arr[index] = i;
        go(index + 1, n, m);
    }
}

int main() {
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> number[i];
    go(0, n, n);
    cout << ans;
}