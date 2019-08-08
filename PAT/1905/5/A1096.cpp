#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    scanf("%lld", &n);
    ll sqr = (ll)sqrt(1.0 * n), len = 0, maxLen = 0, firstN;
    for(int i = 2; i <= sqr; ++i)
    {
        if(n % i == 0)
        {
            len = 1;
            for(int j = i + 1; ; ++j)
            {
                if(n % j == 0)
                    ++len;
                else
                    break;
            }
            if(len > maxLen)
            {
                maxLen = len;
                firstN = i;
            }
        }
    }
    if(maxLen == 0)
        printf("1\n%lld", n);
    else
    {
        printf("%lld\n", maxLen);
        for(int i = 0; i < maxLen; ++i)
        {
            printf("%lld", firstN + i);
            if(i < maxLen - 1)
                printf("*");
        }
    }

    return 0;
}




/*
8:53
9:17
*/

/*
# test case1:
630

# result1:
3
5*6*7

# test case2:
6

# result2:
2
2*3

# test case3:
2

# result3:
1
2
*/