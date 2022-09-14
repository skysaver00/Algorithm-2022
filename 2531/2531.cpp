#include <iostream>

using namespace std;
int arr[30001];
int sushi[3001];

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    for(int i = 0; i < n; i++) cin >> arr[i];

    bool flag = false;
    bool flag2 = false;
    int maxi, ans;
    maxi = -1, ans = 0;
    for(int i = 0; i < k; i++) {
        if(sushi[arr[i]] == 0) flag = true;
        sushi[arr[i]]++;
        if(sushi[arr[i]] > 0 && flag) ans++;
        flag = false;
        if(maxi < ans) maxi = ans;
    }
    int left, right;
    left = 0, right = k - 1;

    while(left / n == 0) {
        if(flag2) ans--;
        flag2 = false;
        sushi[arr[left % n]]--;

        if(sushi[arr[left % n]] == 0) ans--;
        left++;
        right++;

        if(sushi[arr[right % n]] == 0) flag = true;
        sushi[arr[right % n]]++;
        if(sushi[arr[right % n]] > 0 && flag) ans++;
        flag = false;

        //for(int i = 1; i <= 10; i++) cout << sushi[i] << ' ';
        //cout << '\n';

        if(sushi[arr[(left - 1) % n]] == 0 && arr[(left - 1) % n] == c) flag2 = true;
        if(sushi[arr[(right + 1) % n]] == 0 && arr[(right + 1) % n] == c) flag2 = true;
        
        //cout << ans << '\n';
        if(maxi < ans) maxi = ans;
        //cout << left << ' ' << right << '\n';
        //cout << maxi << '\n';
    }
    cout << maxi << '\n';
    return 0;
}