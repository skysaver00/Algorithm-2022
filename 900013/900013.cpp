#include <iostream>
#include <vector>

using namespace std;
vector <int> vec[4];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int k;
        char j;
        cin >> k >> j;

        if(j == 'A') {
            vec[0].push_back(k);
        } else if(j == 'B') {
            vec[1].push_back(k);
        } else if(j == 'B') {
            vec[2].push_back(k);
        } else {
            vec[3].push_back(k);
        }
    }

    while(!vec[0].empty() || !vec[1].empty() || !vec[2].empty() || !vec[3].empty()) {
        int 
    }
}