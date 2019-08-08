#include <cstdio>
#include <cstring>

int input[100005];
int num[100005] = {0};

int main()
{
    int n, value, num_sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &input[i]);
        ++num[input[i]];
    }
    int i;
    for(i = 0; i < n; ++i)
    {
        if(num[input[i]] == 1)
        {
            printf("%d\n", input[i]);
            break;
        }
    }
    if(i == n)
        printf("None\n");

    return 0;
}


/*
16:53
17:25

*/

/*
# test case1:
7 5 31 5 88 67 88 17

# test case2:
5 888 666 666 888 888

*/