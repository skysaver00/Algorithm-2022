#include <iostream>

using namespace std;
string str;
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
    cin >> str;

    makekey(str.length());
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cout << key[i][j] << ' ';
        }cout << '\n';
    }
}