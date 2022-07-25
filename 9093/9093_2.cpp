#include <iostream>

#include <stack>

#include <string>

using namespace std;

int main() {
    stack < char > stack;
    int t;
    cin >> t;
    cin.ignore();

    for (int i = 0; i < t; i++) {
        string sentence;
        getline(cin, sentence);
        sentence += "\n";

        int length = sentence.length();

        for (int j = 0; j < length; j++) {
            if (sentence[j] != ' ' && sentence[j] != '\n') stack.push(sentence[j]);
            else {
                while (!stack.empty()) {
                    cout << stack.top();
                    stack.pop();
                }
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}