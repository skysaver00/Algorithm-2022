#include <iostream>
#include <queue>

using namespace std;
int arr[51][51];

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) cin >> arr[i][j];
    }

    int shx, shy;
    shx = shy = (n / 2) + 1;
    
    for(int i = 0; i < m; i++) {
        int d, s;
        cin >> d >> s;

    }
}