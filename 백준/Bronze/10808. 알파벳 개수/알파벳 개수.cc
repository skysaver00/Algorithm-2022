#include <iostream>

using namespace std;
int alphabet[27];
string word;

int main() {
    cin >> word;
    int len = word.length();
    for(int i = 0; i < len; i++) alphabet[word[i] - 0x61]++;
    for(int i = 0; i < 26; i++) cout << alphabet[i] << ' ';
}