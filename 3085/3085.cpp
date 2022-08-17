#include <iostream>
#include <vector>

using namespace std;
vector <string> real(51);
vector <string> copi(51);

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> copi[i];
    }

    int max = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int now = 1;
            if(i > 0) swap(copi[i - 1][j], copi[i][j]);
            now = 1;
            for(int k = 1; k < n; k++) {
                if(copi[i][k - 1] == copi[i][k]) now++;
                else {
                    if(max < now) max = now;
                    now = 1;
                }
            }
            if(max < now) max = now;
            now = 1;
            for(int k = 1; k < n; k++) {
                if(copi[k - 1][j] == copi[k][j]) now++;
                else {
                    if(max < now) max = now;
                    now = 1;
                }
            }
            if(max < now) max = now;
            if(i > 0) swap(copi[i - 1][j], copi[i][j]);

            if(j > 0) swap(copi[i][j - 1], copi[i][j]);
            now = 1;
            for(int k = 1; k < n; k++) {
                if(copi[i][k - 1] == copi[i][k]) now++;
                else {
                    if(max < now) max = now;
                    now = 1;
                }
            }
            if(max < now) max = now;
            now = 1;
            for(int k = 1; k < n; k++) {
                if(copi[k - 1][j] == copi[k][j]) now++;
                else {
                    if(max < now) max = now;
                    now = 1;
                }
            }
            if(max < now) max = now;
            if(j > 0) swap(copi[i][j - 1], copi[i][j]);

            if(i > 0) swap(copi[i + 1][j], copi[i][j]);
            now = 1;
            for(int k = 1; k < n; k++) {
                if(copi[i][k - 1] == copi[i][k]) now++;
                else {
                    if(max < now) max = now;
                    now = 1;
                }
            }
            if(max < now) max = now;
            now = 1;
            for(int k = 1; k < n; k++) {
                if(copi[k - 1][j] == copi[k][j]) now++;
                else {
                    if(max < now) max = now;
                    now = 1;
                }
            }
            if(max < now) max = now;
            if(i > 0) swap(copi[i + 1][j], copi[i][j]);
            
            if(j > 0) swap(copi[i][j + 1], copi[i][j]);
            now = 1;
            for(int k = 1; k < n; k++) {
                if(copi[i][k - 1] == copi[i][k]) now++;
                else {
                    if(max < now) max = now;
                    now = 1;
                }
            }
            if(max < now) max = now;
            now = 1;
            for(int k = 1; k < n; k++) {
                now = 1;
                if(copi[k - 1][j] == copi[k][j]) now++;
                else {
                    if(max < now) max = now;
                    now = 1;
                }
            }
            if(max < now) max = now;
            if(j > 0) swap(copi[i][j + 1], copi[i][j]);
        }
    }
    cout << max;
}