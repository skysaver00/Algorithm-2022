#include <iostream>
#include <queue>

using namespace std;
queue <pair<int, pair<int, int>>> que;
bool ck[1501][1501];

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int sum = a + b + c;

    que.push({a, {b, c}});

    if(sum % 3 != 0) {
        cout << 0;
        return 0;
    }

    while(!que.empty()) {
        int na, nb, nc;
        na = que.front().first;
        nb = que.front().second.first;
        nc = que.front().second.second;
        if(ck[sum / 3][sum / 3] == 1) {
            cout << 1;
            return 0;
        }

        if(na != nb) {
            if(na > nb) {
                na -= nb;
                nb += nb;
            } else {
                nb -= na;
                na += na;
            }
        }

        if(ck[na][nb] == 0) {
            que.push({na, {nb, nc}});
            ck[na][nb] = 1;
        }

        if(na != nc) {
            if(na > nc) {
                na -= nc;
                nc += nc;
            } else {
                nc -= na;
                na += na;
            }
        }

        if(ck[na][nb] == 0) {
            que.push({na, {nb, nc}});
            ck[na][nb] = 1;
        }

        if(nb != nc) {
            if(nb > nc) {
                nb -= nc;
                nc += nc;
            } else {
                nc -= nb;
                nb += nb;
            }
        }

        if(ck[na][nb] == 0) {
            que.push({na, {nb, nc}});
            ck[na][nb] = 1;
        }

        que.pop();
    }

    cout << 0;
    return 0;
}