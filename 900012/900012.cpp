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
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cout << key[i][j] << ' ';
        }cout << '\n';
    }

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
        cout << fi << se << ' ';
        cout << now << '\n';

        if(now == len) break;
    }
}