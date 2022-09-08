#include <iostream>
#include <queue>
#include <stack>

using namespace std;
queue <int> dragon;
queue <int> que;
stack <int> stk;
int arr[105][105];
int axisx[4] = {0, -1, 0, 1};
int axisy[4] = {1, 0, -1, 0};

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y, d, g;
        cin >> y >> x >> d >> g;
        int newx, newy;
        newx = x;
        newy = y;
        if(newx >= 0 && newx <= 100 && newy >= 0 && newy <= 100) arr[newx][newy] = 1;
        dragon.push(d);
        for(int j = 0; j < g; j++) {
            int top = dragon.top();
            dragon.pop();
            
        }
    }
}