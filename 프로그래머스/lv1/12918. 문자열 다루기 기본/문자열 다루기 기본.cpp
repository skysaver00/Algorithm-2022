#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int len = s.length();
    for(int i = 0; i < len; i++) {
        if(len != 4 && len != 6) {
            answer = false;
            break;
        }
        
        if(s[i] >= '0' && s[i] <= '9') continue;
        else {
            answer = false;
            break;
        }
    }
    
    return answer;
}