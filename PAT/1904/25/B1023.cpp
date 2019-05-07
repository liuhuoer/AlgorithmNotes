#include <cstdio>
#include <cstring>

int main()
{
    int dic[10];
    memset(dic, 0, sizeof(dic));
    int sum = 0;
    for(int i = 0; i < 10; ++i)
    {
        scanf("%d", &dic[i]);
        sum += dic[i];
    }
    for(int i = 1; i < 10; ++i)
    {
        if(dic[i] > 0)
        {
            printf("%d", i);
            --dic[i];
            break;
        }
    }
    for(int i = 0; i < 10; ++i)
    {
        for(; dic[i] > 0; --dic[i])
        {
            printf("%d", i);
        }
    }


    //version 1
    /*
    bool first = true;
    for(int i = 0; i < 10; ++i)
    {
        if(first != true)
        {
            if(dic[i] > 0)
            {
                printf("%d", i);
                --dic[i];
                i = -1;
            }
        }
        else
        {
            first = false;
            continue;
        }
    }
    */

    return 0;
}

/*
18:00
18:17
*/


/*
# test case1:
2 2 0 0 0 3 0 0 1 0
*/