#include <cstdio>

const int down = 4, up = 6, stay = 5;

int main()
{
    int n;
    scanf("%d", &n);
    int now = 0, sum = 0, to;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &to);
        if(to - now > 0)
            sum += (to - now) * up; 
        else if(to - now < 0)
            sum += (now - to) * down;
        now = to;
        sum += stay;
    }
    printf("%d", sum);

    return 0;
}




/*
9:49
10:02
*/

/*
# test case1:
3 2 3 1

# result1:
41
*/