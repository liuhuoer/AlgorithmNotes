#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1010;
int n;
int father[MAXN], isRoot[MAXN] = {0}, course[MAXN] = {0};

bool cmp(int a, int b)
{
    return a > b;
}

void init()
{
    for(int i = 1; i <= n; ++i)
    {
        isRoot[i] = 0;
        father[i] = i;
    }
}

int findFather(int x)
{
    int a = x;
    while(x != father[x])
    {
        x = father[x];
    }
    while(a != father[a])
    {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b)
{
    int af = findFather(a);
    int bf = findFather(b);
    if(af != bf)
        father[af] = bf;
}

int main()
{
    int count = 0;
    scanf("%d", &n);
    init();
    for(int i = 1, k; i <= n; ++i)
    {
        scanf("%d:", &k);
        for(int j = 0, tmp; j < k; ++j)
        {
            scanf("%d", &tmp);
            if(course[tmp] == 0)
                course[tmp] = i;
            Union(i, course[tmp]);
        }
    }
    // isRoot
    for(int i = 1; i <= n; ++i)
    {
        ++isRoot[findFather(i)];
    }
    for(int i = 1; i <= n; ++i)
    {
        if(isRoot[i] != 0)
            ++count;
    }
    // output
    printf("%d\n", count);
    sort(isRoot + 1, isRoot + n + 1, cmp);
    for(int i = 1; i <= count; ++i)
    {
        printf("%d", isRoot[i]);
        if(i < count)
            printf(" ");
    }

    return 0;
}




/*
21:30
23:00
*/

/*
Sample Input:
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
Sample Output:
3
4 3 1
*/