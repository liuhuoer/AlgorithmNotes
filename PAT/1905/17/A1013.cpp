#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 1005;

int n, breakPoint;
vector<int> G[MAXN];
bool vis[MAXN] = {false};

// version 1
 
void dfs(int v)
{
    if(v == breakPoint)
        return;
    vis[v] = true;
    for(int i = 0; i < G[v].size(); ++i)
    {
        if(vis[G[v][i]] == false)
            dfs(G[v][i]);
    }
}

int main()
{
    int m, k;
    scanf("%d %d %d", &n, &m, &k);
    int a, b;
    for(int i = 0; i < m; ++i)
    {
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < k; ++i)
    {
        int block = 0;
        scanf("%d", &breakPoint);
        memset(vis, false, sizeof(vis));
        for(int j = 1; j <= n; ++j)
        {
            if(j != breakPoint && vis[j] == false)
            {
                dfs(j);
                ++block;
            }
        }
        printf("%d\n", block - 1);
    }

    return 0;
}


// version 2
/*
int father[MAXN];

void init()
{
    for(int i = 1; i <= n; ++i)
    {
        father[i] = i;
        vis[i] = false;
    }
}

int findFather(int x)
{
    int a = x;
    while(x != father[x])
        x = father[x];
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
    int fa = father[a];
    int fb = father[b];
    if(fa != fb)
        father[fa] = fb;
}

int main()
{
    int m, k;
    scanf("%d %d %d", &n, &m, &k);
    int a, b;
    for(int i = 0; i < m; ++i)
    {
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < k; ++i)
    {
        scanf("%d", &breakPoint);
        init();
        int block = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j < G[i].size(); ++j)
            {
                if(i == breakPoint || G[i][j] == breakPoint)
                    continue;
                Union(i, G[i][j]);
            }
        }
        for(int i = 1; i <= n; ++i)
        {
            if(i == breakPoint)
                continue;
            int fa = findFather(i);
            if(vis[fa] == false)
            {
                ++block;
                vis[fa] = true;
            }
        }
        printf("%d\n", block - 1);
    }
    
    return 0;
}
*/




/*
10:20
*/


/*
Sample Input:
3 2 3
1 2
1 3
1 2 3
Sample Output:
1
0
0
*/