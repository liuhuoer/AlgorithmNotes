#include <cstdio>

int main()
{
    int n, m, a[105], b[105];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; ++i)
    {
        scanf("%d", &b[i]);
    }
    int mid = (n + m - 1) / 2;
    int count = 0, i, j;
    for(i = 0, j = 0; count < mid;)
    {
        if(a[i] < b[j])
            ++i;
        else
            ++j;
        ++count;
    }
    if(a[i] < b[j])
        printf("%d", a[i]);
    else
        printf("%d", b[j]);

    return 0;
}




/*
12:27
12:46
*/

/*
# test case1:
4 11 12 13 14
5 9 10 15 16 17
# res1:
13
*/