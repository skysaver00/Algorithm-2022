#include <iostream>
#include <queue>
#include <stack>

using namespace std;
stack <int> dragon;
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
        arr[x][y] = 1;
        cout << x << ' ' << y << '\n';
        newx = x + axisx[d];
        newy = y + axisy[d];
        cout << newx << ' ' << newy << '\n';
        if(newx >= 0 && newx <= 100 && newy >= 0 && newy <= 100) arr[newx][newy] = 1;
        dragon.push(d);
        for(int j = 1; j <= g; j++) {
            while(!dragon.empty()) {
                int top = dragon.top();
                dragon.pop();
                int newp = (top + 1) % 4;
                newx = newx + axisx[newp];
                newy = newy + axisy[newp];
                cout << newx << ' ' << newy << '\n';
                if(newx >= 0 && newx <= 100 && newy >= 0 && newy <= 100) arr[newx][newy] = 1;
                stk.push(top);
                que.push(newp);
            }
            while(!que.empty()) {
                int front = que.front();
                que.pop();
                dragon.push(front);
            }
            while(!stk.empty()) {
                int top = stk.top();
                stk.pop();
                dragon.push(top);
            }
            cout << '\n';
        }
    }
}