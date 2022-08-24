#include <iostream>

using namespace std;
int arr[21];
int arr2[21];
int brr[21][21];
bool cnt[21];
bool cnt2[21];
int alp = 999999999;

void go(int index, int start, int n, int m) {
    if(index == m) {
        fill_n(cnt2, 20, false);
        int Ateam, Bteam;
        Ateam = Bteam = 0;
        int l = n - m;

        for(int i = 0; i < m; i++) {
            cnt2[arr[i]] = true;
        }

        int val = 0;
        for(int i = 0; i < n; i++) {
            if(!cnt2[i]) {
                arr2[val] = i;
                val++;
            }
        }

        /*for(int i = 0; i < m; i++) cout << arr[i] << ' ';
        cout << "\n";
        
        for(int i = 0; i < l; i++) cout << arr2[i] << ' ';
        cout << "\n";*/

        for(int i = 0; i < m; i++) {
            for(int j = i; j < m; j++) {
                Ateam += (brr[arr[i]][arr[j]] + brr[arr[j]][arr[i]]);
            }
        }
        
        for(int i = 0; i < l; i++) {
            for(int j = i; j < l; j++) {
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
        go(index + 1, i, n, m);
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

    for(int i = 2; i <= n / 2; i++) go(0, 0, n, i);
    cout << alp;
}