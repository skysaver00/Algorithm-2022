#include <iostream>
#include <algorithm>

using namespace std;
int arr[10];
int brr[10];
int cnt[10];

void go(int index, int n, int m) {
    if(index == m) {
        for(int i = 0; i < m; i++) cout << brr[arr[i]] << ' ';
        cout << "\n";
        return;
    }

    for(int i = 0; i < n; i++) {
        if(cnt[i] > 0) {
            cnt[i]--;
            arr[index] = i;
            go(index + 1, n, m);
            cnt[i]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int temp[10];
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }
    sort(temp,temp + n);
    int k = 0;
    int x = temp[0];
    int c = 1;
    for (int i = 1; i < n; i++) {
        if (x == temp[i]) {
            c += 1;
        } else {
            brr[k] = x;
            cnt[k] = c;
            k += 1;
            x = temp[i];
            c = 1;
        }
    }
    brr[k] = x;
    cnt[k] = c;
    n = k+1;
    go(0, n, m);
}