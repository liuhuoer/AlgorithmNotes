#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXV = 1020;
const int INF = 1000000000;

int N, M, Ds;

bool vis[MAXV];

int G[MAXV][MAXV], d[MAXV];

int getID(char str[])
{
    int len = strlen(str), res = 0;
    for(int i = 0; i < len; ++i)
    {
        if(str[i] != 'G')
            res = res * 10 + str[i] - '0';
    }
    if(str[0] == 'G')
        return res + N;
    else
        return res;
}

void Dijkstra(int s)
{
    fill(d, d + MAXV, INF);
    fill(vis, vis + MAXV, false);
    //memset(vis, false, sizeof(vis));
    d[s] = 0;
    for(int i = 1; i <= N + M; ++i)
    {
        int u = -1, MIN = INF; 
        for(int j = 1; j <= N + M; ++j)
        {
            if(vis[j] == false && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1)
            return;
        vis[u] = true;
        for(int v = 1; v <= N + M; ++v)
        {
            if(vis[v] == false && G[u][v] != INF)
            {
                if(d[u] + G[u][v] < d[v])
                    d[v] = d[u] + G[u][v];
            }
        }
    }
}

int main()
{
    int K;
    fill(G[0], G[0] + MAXV * MAXV, INF);
    scanf("%d%d%d%d", &N, &M, &K, &Ds);
    char s1[5], s2[5];
    for(int i = 0, k1, k2, len; i < K; ++i)
    {
        scanf("%s %s %d", s1, s2, &len);
        k1 = getID(s1);
        k2 = getID(s2);
        G[k1][k2] = len;
        G[k2][k1] = len;
    }
    int ansID = -1;
    double ansD = -1, ansAvg = INF;
    for(int i = N + 1; i <= N + M; ++i)
    {
        double minD = INF, avgD = 0;
        Dijkstra(i);
        for(int j = 1; j <= N; ++j)
        {
            if(d[j] > Ds)
            {
                minD = -1;
                break;
            }
            if(d[j] < minD)
                minD = d[j];
            avgD += 1.0 * d[j] / N;
        }
        if(minD == -1)
            continue;
        if(minD > ansD)
        {
            ansD = minD;
            ansAvg = avgD;
            ansID = i;
        }else if(minD == ansD && avgD < ansAvg){
            ansAvg = avgD;
            ansID = i;
        }
    }
    if(ansID == -1)
        printf("No Solution\n");
    else{
        printf("G%d\n", ansID - N);
        printf("%.1f %.1f\n", ansD, ansAvg);
    }

    return 0;
}




/*
14:58
*/


/*
Sample Input 1:
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2
Sample Output 1:
G1
2.0 3.3
Sample Input 2:
2 1 2 10
1 G1 9
2 G1 20
Sample Output 2:
No Solution
*/