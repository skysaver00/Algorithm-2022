#include <iostream>

using namespace std;
int arr[10];
int cnt[10];

void startdfs(int index, int start, int end) {
    if(index == end) {
        for(int i = 0; i < end; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 1; i <= start; i++) {
        if(cnt[i] == 1) continue;
        cnt[i] = 1;
        arr[index] = i;
        startdfs(index + 1, start, end);
        cnt[i] = 0;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    startdfs(0, n, m);
    return 0;
}