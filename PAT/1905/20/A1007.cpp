#include <cstdio>

const int MAXV = 10005;

int value[MAXV];

int main()
{
    int n;
    scanf("%d", &n);
    bool flag = false;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &value[i]);
        if(value[i] >= 0)
            flag = true;
    }
    if(flag == false)
    {
        printf("0 %d %d\n", value[0], value[n - 1]);
        return 0;
    }
    
    int sum[MAXV];
    int sta[MAXV] = {0};
    sum[0] = value[0];
    for(int i = 1; i < n; ++i)
    {
        if(value[i] <= sum[i - 1] + value[i])
        {
            sum[i] = sum[i - 1] + value[i];
            sta[i] = sta[i - 1];
        }else{
            sum[i] = value[i];
            sta[i] = i;
        }
    }
    int maxI = 0;
    for(int i = 0; i < n; ++i)
    {
        if(sum[i] > sum[maxI])
        {
            maxI = i;
        }
    }
    printf("%d %d %d\n", sum[maxI], value[sta[maxI]], value[maxI]);

    return 0;
}




/*
15:26
16:10
*/


/*
Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
*/