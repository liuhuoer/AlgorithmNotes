#include <cstdio>

int minimum = 1000000005;
int sum[105];

int binarySearch(int left, int right, int t)
{
    int mid;
    while(left < right)
    {
        mid = (left + right) / 2;
        if(sum[mid] > t)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main()
{
    int n, key;
    scanf("%d %d", &n, &key);
    sum[0] = 0;
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];
    }
    for(int i = 1; i <= n; ++i)
    {
        int j = binarySearch(i, n + 1, sum[i - 1] + key);
        if(sum[j - 1] - sum[i - 1] == key)
        {
            minimum = key;
            break;
        }
        else if(j <= n && sum[j] - sum[i - 1] < minimum)
            minimum = sum[j] - sum[i - 1];
    }
    for(int i = 1; i <= n; ++i)
    {
        int j = binarySearch(i, n + 1, sum[i - 1] + minimum);
        if(sum[j - 1] - sum[i - 1] == minimum)
            printf("%d-%d\n", i, j - 1);
    }

    return 0;
}



/*
15:11
15:57
*/


/*
# test case1:
16 15
3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13

# test case2:
5 13
2 4 5 7 9

# test case3:
3 3 
1 2 3

# test case4:
3 5 
2 2 2

# test case5:
1 10
18
*/