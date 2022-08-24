#include <iostream>

using namespace std;
int arr[21];
int arr2[21];
int brr[21][21];
bool cnt[21];
bool cnt2[21];
int alp = 999999999;

void go(int index, int start, int n) {
    if(index == (n / 2)) {
        fill_n(cnt2, 20, false);
        int Ateam, Bteam;
        Ateam = Bteam = 0;

        for(int i = 0; i < (n / 2); i++) {
            cnt2[arr[i]] = true;
        }

        int val = 0;
        for(int i = 0; i < n; i++) {
            if(!cnt2[i]) {
                arr2[val] = i;
                val++;
            }
        }

        for(int i = 0; i < (n / 2); i++) {
            for(int j = i; j < (n / 2); j++) {
                Ateam += (brr[arr[i]][arr[j]] + brr[arr[j]][arr[i]]);
                Bteam += (brr[arr2[i]][arr2[j]] + brr[arr2[j]][arr2[i]]);
            }
        }
        int temp = abs(Ateam - Bteam);
        if(alp > temp) alp = temp;
        return;
    }

    for(int i = start; i < n; i++) {
        if(cnt[i]) continue;
        cnt[i] = true;
        arr[index] = i;
        go(index + 1, i, n);
        cnt[i] = false;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> brr[i][j];
        }
    }
    go(0, 0, n);
    cout << alp;
}