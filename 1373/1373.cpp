#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    int now = 0;
    int len = s.length();

    if(len % 3 == 1) {
        now += (s[0] - 0x30);
        cout << now;
    } else if(len % 3 == 2) {
        now += (s[1] - 0x30);
        now += (s[0] - 0x30) * 2;
        cout << now;
    }

    for(int i = len % 3; i < len; i += 3) {
        now = 0;
        now += (s[i + 2] - 0x30);
        now += (s[i + 1] - 0x30) * 2;
        now += (s[i] - 0x30) * 4;
        cout << now;
    }

    return 0;
}