#include <cstdio>
#include <cstring>

bool dic[105];

void callatz(int value)
{
    while(value != 1)
    {
        if(value % 2 == 0)
            value /= 2;
        else
            value = (value * 3 + 1) / 2;
        dic[value] = false;
    }
}

int main()
{
    memset(dic, true, sizeof(dic));
    int n;
    int value[105];
    memset(value, 0, sizeof(value));
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &value[i]);
        callatz(value[i]);
    }
    bool first = true;
    for(int i = n - 1; i >= 0; --i)
    {
        if(dic[value[i]] == true)
        {
            if(first == false)
                printf(" ");
            printf("%d", value[i]);
            first = false;
        }
    }

    return 0;
}


/*
19:22
19:50
*/

/*
# test case1:
6
3 5 6 7 8 11
*/