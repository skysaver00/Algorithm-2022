#include <string>
#include <vector>
#include <cmath>

using namespace std;
long long digit[64];

int solution(int n, int k) {
    int val = n;
    int now = 0;
    while(val != 0) {
        digit[now] = val % k;
        val /= k;
        now++;
    }
    now--;
    
    for(int i = 0; i <= now / 2; i++) {
        int temp = digit[i];
        digit[i] = digit[now - i];
        digit[now - i] = temp;
    }
    
    long long value = 0;
    int ans, flag;
    ans = 0;
    for(int i = 0; i <= now; i++) {
        flag = 0;
        if(digit[i] == 0) {
            long long squ = sqrt(value);
            if(value == 0 || value == 1) flag = 1;
            for(int j = 2; j <= squ; j++) {
                if(value % j == 0) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) ans++;
            value = 0;
        } else {
            value *= 10;
            value += digit[i];
        }
    }
    
    long long squ = sqrt(value);
    if(value == 0 || value == 1) flag = 1;
    for(int j = 2; j <= squ; j++) {
        if(value % j == 0) {
            flag = 1;
            break;
        }
    }
    if(flag == 0) ans++;
    return ans;
    //(!era[value]) vec.push_back(value);
    
    //int sz = vec.size();
    //int ans = 0;
    //for(int i = 0; i < sz; i++) {
        //(era[vec[i]] == false) ans++;
    //}
    //return ans;
}