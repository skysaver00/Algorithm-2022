#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    stack<char> maker;

    int t;
    cin >> t;
    cin.ignore();
    string str;

    for(int i = 0; i < t; i++) {
        getline(cin, str);
        cout << "DFSFS: " << str << "\n";
        int len = str.length();
        int flag = 0;
        
        for(int j = 0; j < len; j++) {
            if(str[j] != ' ') maker.push(str[j]);

            if(str[j] == ' ') {
                while(!maker.empty()) {
                    if(flag != 0) {
                        cout << " ";
                    }
                    flag++;
                    cout << maker.top();
                    maker.pop();
                }
            } else if(j == len - 1) {
                cout << " ";
                while(!maker.empty()) {
                    cout << maker.top();
                    maker.pop();
                }
            }
        }
        cin.ignore();
        flag = 0;
    }
    return 0;
}