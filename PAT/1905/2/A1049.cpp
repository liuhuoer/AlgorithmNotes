#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    int a = 1, left = 0, now = 0, right = 0, sum = 0;
    while(n / a)
    {
        left = n / (a * 10);
        now = n / a % 10;
        right = n % a;
        if(now == 0)
            sum += left * a;
        else if(now == 1)
            sum += left * a + right + 1;
        else if(now > 1)
            sum += (left + 1) * a;
        a *= 10;
    }
    printf("%d", sum);


    return 0;
}




/*
10:12
#
*/

/*
# test case1:
12

# result1:
5
*/