#include <iostream>

using namespace std;
string str;

int main() {
    while(1) {
        getline(cin, str);
        int len = str.length();
        if(str[0] == 'E' && str[1] == 'N' && str[2] == 'D') break;
        for(int i = len - 1; i >= 0; i--) cout << str[i];
        cout << "\n";
    }
}