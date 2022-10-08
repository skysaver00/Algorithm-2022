#include <string>
#include <vector>
#include <map>

using namespace std;
vector <string> vec1;
vector <string> vec2;
int arr2[1000];
vector <string> vec3;

int solution(string str1, string str2) {
    int len1 = str1.length();
    int len2 = str2.length();
    
    for(int i = 0; i < len1; i++) {
        if(str1[i] >= 'a' && str1[i] <= 'z') str1[i] = str1[i] - 32;
    }
    
    for(int i = 0; i < len2; i++) {
        if(str2[i] >= 'a' && str2[i] <= 'z') str2[i] = str2[i] - 32;
    }
    
    for(int i = 0; i < len1 - 1; i++) {
        string st = "";
        
        int flag = 0;
        if(str1[i] < 'A' || str1[i] > 'Z') flag = 1;
        if(str1[i + 1] < 'A' || str1[i + 1] > 'Z') flag = 1;
        
        if(flag == 1) continue;
        
        st += str1[i];
        st += str1[i + 1];
        vec1.push_back(st);
    }
    
    for(int i = 0; i < len2 - 1; i++) {
        string st = "";
        
        int flag = 0;
        if(str2[i] < 'A' || str2[i] > 'Z') flag = 1;
        if(str2[i + 1] < 'A' || str2[i + 1] > 'Z') flag = 1;
        
        if(flag == 1) continue;
        
        st += str2[i];
        st += str2[i + 1];
        vec2.push_back(st);
    }
    
    if(vec1 > vec2) {
        vec3 = vec1;
        vec1 = vec2;
        vec2 = vec3;
    }
    
    vec3.clear();
    
    int kyo, hap;
    kyo = hap = 0;
    
    int sz, sz2;
    sz = vec1.size();
    sz2 = vec2.size();
    
    for(int i = 0; i < sz; i++) {
        int flag = 0;
        for(int j = 0; j < sz2; j++) {
            if(vec1[i] == vec2[j] && arr2[j] == 0) {
                vec3.push_back(vec1[i]);
                flag = 1;
                arr2[j] = 1;
            }
            if(flag == 1) break;
        }
    }
    
    int sz3 = vec3.size();
    double up, down;
    up = down = 0;
    up = sz3;
    down = sz + sz2 - sz3;
    
    if(down == 0) return 65536;
    
    up /= down;
    int ans = 65536;
    ans *= up;
    
    return ans;
}