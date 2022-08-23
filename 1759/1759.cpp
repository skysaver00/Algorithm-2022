#include <iostream>
#include <algorithm>

using namespace std;
int arr[16];
char brr[16];
bool cnt[16];
int cons, coll;

void go(int index, int start, int n, int m) {
    if(index == m) {
        for(int i = 0; i < m; i++) {
            if(brr[arr[i]] == 'a' || brr[arr[i]] == 'e' || brr[arr[i]] == 'i' || brr[arr[i]] == 'o' || brr[arr[i]] == 'u' ) coll++;
            else cons++;
        }
        if(cons >= 2 && coll >= 1) {
            for(int i = 0; i < m; i++) cout << brr[arr[i]];
            cout << '\n';
        }
        cons = coll = 0;
        return;
    }

    for(int i = start; i < n; i++) {
        if(cnt[i]) continue;
        cnt[i] = true;
        arr[index] = i;
        go(index + 1, i, n, m);
        cnt[i] = false;
    }
}

int main() {
    int l, c;
    cin >> l >> c;
    for(int i = 0; i < c; i++) cin >> brr[i];
    sort(brr, brr + c);
    go(0, 0, c, l);
}