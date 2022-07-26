#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> queue;
    int n, k;
    int arr[5001];
    cin >> n >> k;

    for(int i = 1; i <= n; i++) queue.push(i);

    int now = 1;
    int now2 = 0;
    while(!queue.empty()) {
        if(now % k != 0) {
            int out = queue.front();
            queue.pop();
            queue.push(out);
        } else if(now % k == 0) {
            arr[now2++] = queue.front();
            queue.pop();
        }
        now++;
    }

    cout << "<";
    for(int i = 0; i < n - 1; i++) cout << arr[i] << ", ";
    cout << arr[n - 1] << ">\n";

    return 0;
}