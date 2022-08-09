#include <iostream>
#include <stack>

using namespace std;
int ans[1001];
int arr[1001];
int front[1001];

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        ans[i] = 1;
        front[i] = -1;
    }

    int max = 0;
    int maxnow = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i] && ans[j] + 1 > ans[i]) {
                ans[i] = ans[j] + 1;
                front[i] = j;
            }
        }
        if(ans[i] > max) {
            max = ans[i];
            maxnow = i;
        }
    }

    stack<int> trail;
    while(maxnow != -1) {
        trail.push(arr[maxnow]);
        maxnow = front[maxnow];
    }

    cout << max << "\n";
    while(!trail.empty()) {
        cout << trail.top() << ' ';
        trail.pop();
    }
    return 0;
}