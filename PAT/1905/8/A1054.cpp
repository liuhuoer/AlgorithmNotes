#include <cstdio>
#include <map>
using namespace std;

map<int, int> mii;

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int num;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            scanf("%d", &num);
            if(mii.find(num) != mii.end())
                ++mii[num];
            else
                mii[num] = 0;
        }
    }
    int color, max = -1;
    for(map<int, int>::iterator beg = mii.begin(); beg != mii.end(); ++beg)
    {
        if(max < beg->second)
        {
            max = beg->second;
            color = beg->first;
        }
    }
    printf("%d", color);

    return 0;
}




/*
16:22
16:36
*/

/*
# test case1:
5 3
0 0 255 16777215 24
24 24 0 0 24
24 0 24 24 24

# result1:
24
*/