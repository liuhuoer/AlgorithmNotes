#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, key;
    scanf("%d %d", &n, &key);
    int value[100005];
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &value[i]);
    }
    sort(value, value + n);
    int left = 0, right = n - 1;
    while(left < right)
    {
        if(value[left] + value[right] == key)
            break;
        else if(value[left] + value[right] < key)
            ++left;
        else if(value[left] + value[right] > key)
            --right;
    }
    if(left != right)
        printf("%d %d\n", value[left], value[right]);
    else
        printf("No Solution");

    return 0;
}




/*
14:02
14:24
*/


/*
# test case1:
8 15
1 2 8 7 2 4 11 15

#result1:
4 11

# test case2:
7 14
1 8 7 2 4 11 15

# result2:
No Solution

# test case3:
6 14
4 10 7 7 2 12

# result3:
2 12
*/