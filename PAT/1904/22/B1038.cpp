#include <cstdio>
#include <cstring>

int num[105];

int main()
{
    memset(num, 0, sizeof(num));
    int n, m, grade; 
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &grade);
        ++num[grade];
    }
    scanf("%d", &m);
    for(int i = 0; i < m; ++i)
    {
        scanf("%d", &grade);
        printf("%d", num[grade]);
        if(i != m - 1)
            printf(" ");
    }

    return 0;
}

/*
15:35
15:46
*/

/*
# test case1:
10
60 75 90 55 75 99 82 90 75 50
3 75 90 88
*/