#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dic[100010];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i)
    {
        int value;
        scanf("%d", &value);
        ++dic[value];
    }
    for(int i = 1; i < m; ++i)
    {
        if(dic[i] && dic[m - i]) 
        {
            if(i == m - i && dic[i] <= 1)
            {
                continue;
            }
            printf("%d %d\n", i, m - i);
            return 0;
        }
    }
    printf("No Solution\n");

    return 0;
}


/*
17:21
17:44
*/

/*
#test case1:
8 15
1 2 8 7 2 4 11 15

#test case2:
7 14
1 8 7 2 4 11 15
*/