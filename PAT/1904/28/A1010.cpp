#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

LL Info = (1LL << 63) - 1;

LL map[256] = {0};
void init()
{
    for(char c = '0'; c <= '9'; ++c)
        map[c] = c - '0';
    for(char c = 'a'; c <= 'z'; ++c)
        map[c] = c - 'a';
}

LL convDecimal(char N1[], int radix, LL t)
{
    LL ans = 0;
    int len = strlen(N1);
    for(int i = 0; i < len; ++i)
    {
        ans = ans * radix + map[N1[i]];
        if(ans < 0 || ans > t)
            return -1;
    }
    return ans;
}

LL findLagestDigit(char* N)
{
    int max = -1, len = strlen(N);
    for(int i = 0; i < len; ++i)
    {
        if(map[N[i]] > max)
            max = map[N[i]];
    }
    return max + 1;
}

int cmp(char* N, LL mid, LL t)
{
    LL num = convDecimal(N, mid, t);
    if(num < 0)
        return 1;
    if(num == t)
        return 0;
    else if(num < t)
        return -1;
    else 
        return 1;
}

LL binarySearch(char* N, LL l, LL r, LL t)
{
    LL mid;
    while(l < r)
    {
        mid = (l + r) / 2;
        int flag = cmp(N, mid, t);
        if(-1 == flag)
            l = mid + 1;
        else if(flag == 0)
            return mid;
        else if(flag > 0)
            r = mid - 1;
    }
    return -1;
}

int main()
{
    init();
    int tag, radix;
    char N1[11], N2[11], tmp[11];
    scanf("%s %s %d %d", N1, N2, &tag, &radix);
    if(tag == 2)
    {
        strcpy(tmp, N1);
        strcpy(N1, N2);
        strcpy(N2, tmp);
    }
    LL t = convDecimal(N1, radix, Info);
    LL low = findLagestDigit(N2);
    LL high = max(low, t) + 1;
    LL ans = binarySearch(N2, low, high, t);
    if(-1 == ans)
        printf("Impossible\n");
    else
        printf("%d\n", ans);
    
    return 0;
}


/*
15:58
22:01
*/


/*
# test case1:
6 110 1 10

# test case2:
1 ab 1 2

# test case3:
s9jix hj 1 36

# test result3:
2792614

*/