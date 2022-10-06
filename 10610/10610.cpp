#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    int len = str.length();

    int ans = 0;
    bool flag = false;
    for(int i = 0; i < len; i++) {
        if(str[i] == '0') flag = true;
        else ans += str[i] - 0x30;
    }

    if(flag )
}