#include <iostream>

using namespace std;
bool arr[500001];
bool pos[10];

int main() {
    int n, m;
    cin >> n;
    int len = 0;
    int temp = n;
    while(temp != 0) {
        len++;
        temp /= 10;
    }
    cin >> m;

    for(int i = 0; i < m; i++) {
        int button;
        cin >> button;
        pos[button] = true;
    }

    if(pos[0] == true) arr[0] = true;
    for(int i = 1; i <= 500000; i++) {
        int check = i;
        bool flag = false;
        while(!flag) {
            if(check == 0) flag = true;
            int t = check % 10;
            if(pos[t] == true) {
                arr[i] = true;
                break;
            }
            check /= 10;
        }
    }

    int down, up;
    down = up = n;
    int count = 0;
    cout << arr[500000];
    while(arr[down] == true && arr[up] == true) {
        count++;
        down--;
        up++;
    }

    if(len + count < n - 100) cout << len + count;
    else cout << n - 100;
}