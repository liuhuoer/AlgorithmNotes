#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXV = 510;
const int INF = 1000000000;
int N;

int G[MAXV][MAXV];
bool vis[MAXV] = {false};
int d[MAXV], weight[MAXV];
vector<int> pre[MAXV], path, tmpPath;
int miniNeed = INF, miniRemain = INF;

void Dijkstra(int s)
{
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for(int i = 0; i <= N; ++i)
    {
        int u = -1, MIN = INF;
        for(int j = 0; j <= N; ++j)
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
        for(int v = 0; v <= N; ++v)
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

void DFS(int v)
{
    int remain = 0, need = 0; 
    if(v == 0)
    {
        tmpPath.push_back(v);
        for(int k = tmpPath.size() - 1; k >= 0; --k)
        {
            int i = tmpPath[k];
            if(weight[i] > 0)
            {
                remain += weight[i];
            }else{
                if(remain > abs(weight[i]))
                {
                    remain -= abs(weight[i]);
                }else{
                    need += abs(weight[i]) - remain;
                    remain = 0;
                }
            }
        }
        if(need < miniNeed)
        {
            miniNeed = need;
            miniRemain = remain;
            path = tmpPath;
        }else if(need == miniNeed && remain < miniRemain){
            miniRemain = remain;
            path = tmpPath;
        }
        tmpPath.pop_back();
        return;
    }
    tmpPath.push_back(v);
    for(int i = 0; i < pre[v].size(); ++i)
    {
        DFS(pre[v][i]);
    }
    tmpPath.pop_back();
}


int main()
{
    fill(G[0], G[0] + MAXV * MAXV, INF);
    int Lmax, Sp, M;
    scanf("%d%d%d%d", &Lmax, &N, &Sp, &M);
    for(int i = 1; i <= N; ++i)
    {
        scanf("%d", &weight[i]);
        weight[i] -= (Lmax / 2);
    }
    int u, v;
    for(int i = 0; i < M; ++i)
    {
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra(0);
    DFS(Sp);
    printf("%d ", miniNeed);
    for(int i = path.size() - 1; i >= 0; --i)
    {
        printf("%d", path[i]);
        if(i != 0)
            printf("->");
    }
    printf(" %d", miniRemain);

    return 0;
}




/*
20:41
*/

/*
Sample Input:
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
Sample Output:
3 0->2->3 0
*/