#include <stdio.h>
#include <algorithm>
using namespace std;

long long lan[10001];
int main()
{
    int have, need;
    scanf("%d %d", &have, &need);

    for(int i = 0; i < have; i++) scanf("%lld", &lan[i]);
    long long left = 1;
    long long right = 0x7fffffff;

    while(left <= right)
    {
        long long mid = (left + right) / 2;
        long long result = 0;

        for(int i = 0; i < have; i++) result += (lan[i] / mid);

        if(result >= need)
        {
            left = mid + 1;
        }
        else right = mid - 1;

    }

    printf("%lld\n", left - 1);

    return 0;
}
