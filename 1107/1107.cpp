#include <iostream>

using namespace std;
bool arr[1000001];
bool pos[10];

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    for(int i = 0; i < m; i++) {
        int button;
        cin >> button;
        pos[button] = true;
    }

    if(pos[0] == true) arr[0] = true;
    for(int i = 1; i <= 1000000; i++) {
        int check = i;
        while(check != 0) {
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
    int countdown = 0;
    int countup = 0;
    int count = 0;
    int len = 0;

    while(down >= 0 && arr[down] == true) {
        countdown++;
        down--;
    }
    if(down < 0) countdown = 99999999;
    while(up <= 1000000 && arr[up] == true) {
        countup++;
        up++;
    }
    if(up > 1000000) countup = 99999999;
    if(countdown < countup) {
        count = countdown;
        if(down == 0) len = 1;
        while(down != 0) {
            down /= 10;
            len++;
        }
    }
    else {
        count = countup;
        if(up == 0) len = 1;
        while(up != 0) {
            up /= 10;
            len++;
        }
    }

    if(len + count < abs(n - 100)) cout << len + count;
    else cout << abs(n - 100);
}