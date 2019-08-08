#include <cstdio>
#include <cmath>
using namespace std;

bool isPrame(int n)
{
    if(n <= 1)
        return false;
    int sqr = (int)sqrt(1.0 * n);
    for(int i = 2; i <= sqr; ++i)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int reverse(int N, int radix)
{
    int itoc[10005];
    int count = 0, res = 0;
    do{
        itoc[count++] = N % radix;
        N /= radix;
    }while(N);
    for(int i = 0; i < count; ++i)
    {
        res = res * radix + itoc[i];
    }
    return res;
}

int main()
{
    int N, radix, revN;
    while(scanf("%d", &N) != EOF)
    {
        if(N < 0)
            break;
        scanf("%d", &radix);
        revN = reverse(N, radix);
        if(isPrame(N) && isPrame(revN))
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}




/*
21:24
21:48
*/

/*
# test case1:
73 10
23 2
23 10
-2

# result1:
Yes
Yes
No
*/