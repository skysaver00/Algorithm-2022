#include <iostream>
using namespace std;

int main() {
    while(1) {
        string str;
        getline(cin, str);
        cin.ignore();
        cout << str << "\n";

        if(str[0] == '#') {
            cout << "Flag!!\n";
            cin.ignore();
            break;
        }
        int len = str.length();
        int ans = 0;
        for(int i = 0; i < len; i++) {
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') ans++;
            if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') ans++;
        }
        cout << ans << "\n";
    }
}