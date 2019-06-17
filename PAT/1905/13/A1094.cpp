#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 105;
int n, numdep[MAXN] = {0}, maxNumGen = 0;

struct Node
{
    int depth;
    vector<int> children;
} dics[MAXN];

void DFS(int root, int depth)
{
    dics[root].depth = depth;
    int sz = dics[root].children.size();
    if(sz == 0)
        return;
    for(int i = 0; i < sz; ++i)
    {
        DFS(dics[root].children[i], depth + 1);
    }
}

void findLargest()
{
    int maxDep = -1;
    for(int i = 1; i <= n; ++i)
    {
        ++numdep[dics[i].depth];
        if(numdep[dics[i].depth] > maxNumGen)
        {
            maxNumGen = numdep[dics[i].depth];
            maxDep = dics[i].depth;
        }
    }
    printf("%d %d\n", maxNumGen, maxDep);
}

int main()
{
    int m;
    scanf("%d %d", &n, &m);
    int k, num, tmp;
    for(int i = 0; i < m; ++i)
    {
        scanf("%d %d", &k, &num);
        for(int j = 0; j < num; ++j)
        {
            scanf("%d", &tmp);
            dics[k].children.push_back(tmp);
        }
    }
    DFS(1, 1);
    findLargest();

    return 0;
}




/*
16:46
17:45
*/


/*
Sample Input:
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18
Sample Output:
9 4
*/