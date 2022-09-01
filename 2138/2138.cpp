#include <iostream>

using namespace std;
string str;
bool arr[100001];
bool arr2[100001];
bool brr[100001];
int n;

int press(bool x) {
    int val = 0;
    if(!x) {
        arr[0] = !arr[0];
        arr[1] = !arr[1];
        val++;
    } else {}

    for(int i = 1; i < n - 1; i++) {
        if(arr[i - 1] != brr[i - 1]) {
            arr[i - 1] = !arr[i - 1];
            arr[i] = !arr[i];
            arr[i + 1] = !arr[i + 1];
            val++;
        }
    }

    if(arr[n - 1] != brr[n - 1]) {
        arr[n - 2] = !arr[n - 2];
        arr[n - 1] = !arr[n - 1];
        val++;
    }

    return val;
}

int main() {
    cin >> n;
    cin >> str;
    for(int i = 0; i < n; i++) {
        arr[i] = str[i] - 0x30;
        arr2[i] = arr[i];
    }
    cin >> str;
    for(int i = 0; i < n; i++) brr[i] = str[i] - 0x30;

    int ans1, ans2;
    ans1 = ans2 = 0;

    int ans = 999999;
    bool flag = false;
    ans1 = press(false);
    for(int i = 0; i < n; i++) {
        if(arr[i] != brr[i]) {
            flag = true;
            break;
        }
    }
    if(!flag) if(ans > ans1) ans = ans1;
    for(int i = 0; i < n; i++) arr[i] = arr2[i];
    ans2 = press(true);
    for(int i = 0; i < n; i++) {
        if(arr[i] != brr[i]) {
            flag = true;
            break;
        }
    }
    if(!flag) if(ans > ans2) ans = ans2;
    if(ans >= 200000) cout << -1;
    else cout << ans;
}