#include <iostream>

using namespace std;
string real[51];
string copi[51];

void makecopy(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            copi[i][j] = real[i][j];
        }
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> real[i][j];
        }
    }

    int max = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << i  << j << "\n";
            makecopy(n);
            int temp;
            if(i > 0) {
                temp = copi[i - 1][j];
                copi[i - 1][j] = copi[i][j];
                copi[i][j] = temp;
            }
            
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << copi[i][j] << ' ';
        }cout << "\n";
    }cout << "\n";

            for(int k = 1; k < n; k++) {
                int now = 1;
                if(copi[i][k - 1] == copi[i][k]) now++;
                else {
                    if(max < now) max = now;
                    now = 1;
                }
            }
            makecopy(n);
            if(j > 0) {
                temp = copi[i][j - 1];
                copi[i][j] = copi[i][j - 1];
                copi[i][j] = temp;
            }
            
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << copi[i][j] << ' ';
        }cout << "\n";
    }cout << "\n";

            for(int k = 1; k < n; k++) {
                int now = 1;
                if(copi[k - 1][j] == copi[k][j]) now++;
                else {
                    if(max < now) max = now;
                    now = 1;
                }
            }
            makecopy(n);
            if(i < n - 1) {
                temp = copi[i + 1][j];
                copi[i + 1][j] = copi[i][j];
                copi[i][j] = temp;
            }
            
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << copi[i][j] << ' ';
        }cout << "\n";
    }cout << "\n";

            for(int k = 1; k < n; k++) {
                int now = 1;
                if(copi[i][k - 1] == copi[i][k]) now++;
                else {
                    if(max < now) max = now;
                    now = 1;
                }
            }
            makecopy(n);
            if(j < n - 1) {
                temp = copi[i][j + 1];
                copi[i][j] = copi[i][j + 1];
                copi[i][j] = temp;
            }
            
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << copi[i][j] << ' ';
        }cout << "\n";
    }cout << "\n";

            for(int k = 1; k < n; k++) {
                int now = 1;
                if(copi[k - 1][j] == copi[k][j]) now++;
                else {
                    if(max < now) max = now;
                    now = 1;
                }
            }
        }
    }
    cout << max;
}