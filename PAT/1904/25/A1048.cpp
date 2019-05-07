#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool dic[100010] = {false};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i)
    {
        int value;
        scanf("%d", &value);
        dic[value] = true;
    }
    for(int i = 1; i < m; ++i)
    {
        if(dic[i] == true && dic[m - i] == true 
                    && i != m - i 
                    && m - i > 0)
        {
            printf("%d %d\n", i, m - i);
            return 0;
        }
    }
    printf("No Solution");

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