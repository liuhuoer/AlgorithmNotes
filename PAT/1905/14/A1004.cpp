#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 105;
int n, maxDep = 0;
int leftNum[MAXN] = {0};

struct Node
{
    int depth;
    vector<int> children;
} dics[MAXN];

void DFS(int root, int depth)
{
    int sz = dics[root].children.size();
    dics[root].depth = depth;
    if(depth > maxDep)
        maxDep = depth;
    if(sz == 0)
    {
        ++leftNum[depth];
        return;
    }
    for(int i = 0; i < sz; ++i)
    {

        DFS(dics[root].children[i], depth + 1);
    }
}

int main()
{
    int m, tmp, k, tmpChild;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i)
    {
        scanf("%d %d", &tmp, &k);
        for(int j = 0; j < k; ++j)
        {
            scanf("%d", &tmpChild);
            dics[tmp].children.push_back(tmpChild);
        }
    }
    DFS(1, 0);
    for(int i = 0; i <= maxDep; ++i)
    {
        printf("%d", leftNum[i]);
        if(i != maxDep)
            printf(" ");
    }

    return 0;
}




/*
19:32
20:07
*/

/*
Sample Input:
2 1
01 1 02
Sample Output:
0 1
*/