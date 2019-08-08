#include<cstdio>
#include<set>
using namespace std;
const int MAXN = 55;

set<int> si[MAXN];

void compare(int a, int b)
{
    int totalNum = si[a].size(), sameNum = 0;
    for(set<int>::iterator beg = si[b].begin(); beg != si[b].end(); ++beg)
    {
        if(si[a].find(*beg) != si[a].end())
            ++sameNum;
        else
            ++totalNum;
    }
    printf("%.1f%%\n", sameNum * 100.0 / totalNum);
}

int main()
{
    int n, m, value;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &m);
        for(int j = 0; j < m; ++j)
        {
            scanf("%d", &value);
            si[i + 1].insert(value);
        }
    }
    int query, a, b;
    scanf("%d", &query);
    for(int i = 0; i < query; ++i)
    {
        scanf("%d%d", &a, &b);
        compare(a, b);
    }

    return 0;
}




/*
17:23
16:02
*/

/*
# test case1:
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
*/