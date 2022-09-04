#include <iostream>

using namespace std;
string str, str2;
char key[6][6];
bool alphabet[27];

void makekey(int len) {
    int now = 0;
    for(int i = 0; i < len; i++) {
        if(alphabet[str[i] - 0x41]) continue;
        int x, y;
        x = now / 5;
        y = now % 5;
        key[x][y] = str[i];
        alphabet[str[i] - 0x41] = true;
        now++;
    }
    for(int i = 0; i < 26; i++) {
        if(alphabet[i]) continue;
        if(i == 9) continue;
        int x, y;
        x = now / 5;
        y = now % 5;
        key[x][y] = i + 0x41;
        now++;
    }
}

int main() {
    cin >> str2 >> str;

    makekey(str.length());

    int now = 0;
    int len = str2.length();
    for(int i = now; i < len;) {
        char fi, se;
        fi = str2[now];
        now++;
        if(now == len) se = 'X';
        else if(str2[now] == fi) {
            if(fi == 'X') se = 'Q';
            else se = 'X';
        }
        else {
            se = str2[now];
            now++;
        }

        int fx, fy;
        int sx, sy;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(fi == key[i][j]) {
                    fx = i;
                    fy = j;
                }
                if(se == key[i][j]) {
                    sx = i;
                    sy = j;
                }
            }
        }
        if(fx == sx) {
            fi = key[fx][(fy + 1) % 5];
            se = key[sx][(sy + 1) % 5];
        } else if(fy == sy) {
            fi = key[(fx + 1) % 5][fy];
            se = key[(sx + 1) % 5][sy];
        } else {
            fi = key[fx][sy];
            se = key[sx][fy];
        }
        cout << fi << se;
        if(now == len) break;
    }
}