#include <iostream>

using namespace std;
int ans[14];
int arr[14];
int brr[14];
int minimum = 1000000001;
int maximum = -1000000001;
int check[14];

void go(int index, int n) {
    if(index == n) {
        int answer = ans[0];
        for(int i = 0; i < n; i++) {
            if(arr[brr[i]] == 0) answer += ans[i + 1];
            if(arr[brr[i]] == 1) answer -= ans[i + 1];
            if(arr[brr[i]] == 2) answer *= ans[i + 1];
            if(arr[brr[i]] == 3) answer /= ans[i + 1];
        }
        if(minimum > answer) minimum = answer;
        if(maximum < answer) maximum = answer;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(check[i]) continue;
        check[i] = true;
        brr[index] = i;
        go(index + 1, n);
        check[i] = false;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> ans[i];

    int now = 0;
    for(int i = 0; i < 4; i++) {
        int val;
        cin >> val;
        for(int j = 0; j < val; j++) {
            arr[now] = i;
            now++;
        }
    }
    
    go(0, n - 1);
    cout << maximum << '\n';
    cout << minimum;
}