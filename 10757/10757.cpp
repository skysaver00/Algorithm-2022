#include <iostream>

using namespace std;
int A[10002];
int B[10002];
int ANS[10002];
string aa, bb;

void write() {
    int lena = aa.length();
    int lenb = bb.length();

    for(int i = 0; i < lena; i++) {
        A[lena - 1 - i] = aa[i] - 0x30;
    }

    for(int i = 0; i < lenb; i++) {
        B[lenb - 1 - i] = bb[i] - 0x30;
    }
}

int main() {
    cin >> aa >> bb;

    write();

    int lena = aa.length();
    int lenb = bb.length();

    int lenc;
    if(lena < lenb) lenc = lenb;
    else lenc = lena;

    for(int i = 0; i <= lenc; i++) {
        ANS[i] = A[i] + B[i];
        if(ANS[i] > 9) {
            A[i + 1]++;
            ANS[i] -= 10;
        }
    }

    for(int i = lenc; i >= 0; i--) {
        if(i == lenc && ANS[i] == 0) continue;
        cout << ANS[i];    
    }
    cout << "\n"; 

    return 0;
}