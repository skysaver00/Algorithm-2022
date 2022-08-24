#include <cstdio>
bool num[21];

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int val;
        char str[8];
        scanf("%s", str);

        if(str[1] == 'd') {
            scanf("%d", &val);
            num[val] = true;
        }
        else if(str[0] == 'c') {
            scanf("%d", &val);
            if(num[val]) printf("1\n");
            else printf("0\n");
        } 
        else if(str[0] == 'r') {
            scanf("%d", &val);
            num[val] = false;
        }
        else if(str[0] == 't') {
            scanf("%d", &val);
            num[val] = !num[val];
        }
        else if(str[1] == 'l') {
            for (int i = 1; i <= 20; i++) num[i] = true;
        }
        else {
            for(int i = 1; i <= 20; i++) num[i] = false;
        }
    }
    
    return 0;
}