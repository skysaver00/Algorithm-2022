#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        string PS;
        cin >> PS;
        int len = PS.length();

        int val = 0;
        int flag = 1;
        for(int j = 0; j < len; j++) {
            if(PS[j] == '(') val++;
            else if(PS[j] == ')') {
                if(val == 0) {
                    flag = 0;
                    break;
                } else {
                    val--;
                }
            }
        }

        if(flag == 1 && val == 0) {
            cout << "YES\n";
        } else {
            val = 0;
            cout << "NO\n";
        }
    }
    return 0;
}