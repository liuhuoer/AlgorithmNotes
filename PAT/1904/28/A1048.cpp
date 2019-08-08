#include <cstdio>
#include <algorithm>

using namespace std;

int value[100005];

int binarySearch(int left, int right, int key)
{
    int mid;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(value[mid] == key)
            return mid;
        else if(value[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main()
{
    int n, key;
    scanf("%d%d", &n, &key);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &value[i]);
    }
    sort(value, value + n);
    int i;
    for(i = 0; i < n; ++i)
    {
        int j = binarySearch(0, n - 1, key - value[i]);
        if(j != -1 && i != j)
        {
            printf("%d %d\n", value[i], value[j]);
            break;
        }
    }
    if(i == n)
        printf("No Solution\n");

    return 0;
}

/*
16:18
16:34
*/

/*
# test case1:
8 15
1 2 8 7 2 4 11 15

# test case2:
7 14
1 8 7 2 4 11 15
*/