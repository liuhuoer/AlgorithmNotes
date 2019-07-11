#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXV = 510;
const int INF = 1000000000;
int n, st;

bool vis[MAXV] = {false};
int miniCost = INF;

int G[MAXV][MAXV];
int d[MAXV], cost[MAXV][MAXV];
vector<int> pre[MAXV], tmpPath, path;

void Dijkstra(int s)
{
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for(int i = 0; i < n; ++i)
    {
        int u = -1, MIN = INF;
        for(int j = 0; j < n; ++j)
        {
            if(vis[j] == false && d[j] < MIN)
            {
                MIN = d[j];
                u = j;
            }
        }
        if(u == -1)
            return;
        vis[u] = true;
        for(int v = 0; v < n; ++v)
        {
            if(vis[v] == false && G[u][v] != INF)
            {
                if(d[u] + G[u][v] < d[v])
                {
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(d[u] + G[u][v] == d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int s)
{
    int costTmp = 0;
    if(s == st)
    {
        tmpPath.push_back(s);
        for(int i = tmpPath.size() - 1; i > 0; --i)
        {
            int id = tmpPath[i];
            int idPre = tmpPath[i - 1];
            costTmp += cost[id][idPre];
        }
        if(costTmp < miniCost)
        {
            miniCost = costTmp;
            path = tmpPath;
        }
        tmpPath.pop_back();
        return;
    }
    tmpPath.push_back(s);
    for(int i = 0; i < pre[s].size(); ++i)
    {
        DFS(pre[s][i]);
    }
    tmpPath.pop_back();
}

int main()
{
    int m, de;
    fill(G[0], G[0] + MAXV * MAXV, INF);
    fill(cost[0], cost[0] + MAXV * MAXV, INF);
    scanf("%d%d%d%d", &n, &m, &st, &de);
    int u, v;
    for(int i = 0; i < m; ++i)
    {
        scanf("%d%d", &u, &v);
        scanf("%d%d", &G[u][v], &cost[u][v]);
        G[v][u] = G[u][v], cost[v][u] = cost[u][v];
    }
    Dijkstra(st);
    DFS(de);
    for(int i = path.size() - 1; i >= 0; --i)
    {
        printf("%d ", path[i]);
    }
    printf("%d %d", d[de], miniCost);

    return 0;
}




/*
8:57
10:18
20:49
*/

/*
Sample Input:
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output:
0 2 3 3 40
*/