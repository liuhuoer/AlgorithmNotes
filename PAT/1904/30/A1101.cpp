#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 105;

int main()
{
    int n;
    scanf("%d", &n);
    int value[MAXN];
    bool flag[MAXN];
    memset(flag, true, sizeof(flag));
    int max = 0, min = MAXN;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &value[i]);
        if(value[i] < max)
            flag[i] = false;
        else
            max = value[i];
    }
    int count = 0;
    for(int i = n - 1; i >= 0; --i)
    {
        if(value[i] > min)
            flag[i] = false;
        else
            min = value[i];

        if(flag[i])
            ++count;
    }
    printf("%d\n", count);
    for(int i = 0; i < n; ++i)
    {
        if(flag[i])
        {
            printf("%d", value[i]);
            if(i != n - 1)
                printf(" ");
        }
    }

    return 0;
}




/*
20:07
20:38
*/

/*
# test case1:
5
1 3 2 4 5

# result1:
3
1 4 5
*/