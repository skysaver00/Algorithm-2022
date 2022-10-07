#include <iostream>

using namespace std;
int arr[10];
bool cnt[10];

void startper(int a, int b, int c) {
    if(a == c) {
        int flag = 1;
        if(a < 3) flag = 1;
        else {
            for(int i = 0; i < a - 2; i++) {
                for(int j = i + 1; j < a - 1; j++) {
                    for(int k = j + 1; k < a; k++) {
                        if(arr[i] > arr[j]) if(arr[j] < arr[k]) if(arr[i] > arr[k]) flag = 0;
                        if(flag == 0) break;
                    }
                    if(flag == 0) break;
                }
                if(flag == 0) break;
            }
        }

        if(flag == 1) {
            for(int i = 0; i < a; i++) cout << arr[i] << ' ';
            cout << '\n';
        }
        return;
    }

    for(int i = 1; i <= b; i++) {
        if(cnt[i] == true) continue;
        arr[a] = i;
        cnt[i] = true;
        startper(a + 1, b, c);
        cnt[i] = false;
    }
}

int main() {
    int n;
    cin >> n;

    startper(0, n, n);
}