#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int INF = 1000000000;
const int MAXV = 205;

int N, M;
string st;
map<string, int> city2id;
map<int, string> id2city;

int G[MAXV][MAXV], d[MAXV], weight[MAXV];
vector<int> path, tmpPath, pre[MAXV];
bool vis[MAXV] = {false};

int numRoad = 0, minCost = 0, maxHappy = 0, maxAvgHap = 0;

void Dijkstra(int s)
{
    d[s] = 0;
    for(int i = 0; i < N; ++i)
    {
        int u = -1, MIN = INF;
        for(int j = 0; j < N; ++j)
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
        for(int v = 0; v < N; ++v)
        {
            if(vis[v] == false && G[u][v] != INF)
            {
                if(d[v] > d[u] + G[u][v])
                {
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(d[v] == d[u] + G[u][v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int s)
{
    int a = city2id[st];
    if(s == city2id[st])
    {
        tmpPath.push_back(s);
        ++numRoad;
        int sumHap = 0;
        for(int i = tmpPath.size() - 2, id; i >= 0; --i)
        {
            id = tmpPath[i];
            sumHap += weight[id];
        }
        int avgHap = sumHap / (tmpPath.size() - 1);
        if(sumHap > maxHappy)
        {
            maxHappy = sumHap;
            maxAvgHap = avgHap;
            path = tmpPath;
        }else if(sumHap == maxHappy && avgHap > maxAvgHap){
            maxAvgHap = avgHap;
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
    fill(G[0], G[0] + MAXV * MAXV, INF);
    fill(d, d + MAXV, INF);
    string city1, city2;
    cin >> N >> M >> st;
    city2id[st] = 0;
    id2city[0] = st;
    int id = 1;
    for(int i = 0, happyness; i < N - 1; ++i, ++id)
    {
        cin >> city1 >> happyness;
        id2city[id] = city1;
        city2id[city1] = id;
        weight[id] = happyness;
    }
    for(int i = 0, cost, id1, id2; i < M; ++i)
    {
        cin >> city1 >> city2 >> cost;
        id1 = city2id[city1];
        id2 = city2id[city2];
        G[id1][id2] = cost;
        G[id2][id1] = cost;
    }
    Dijkstra(0);
    int idEnd = city2id["ROM"];
    DFS(idEnd);
    printf("%d %d %d %d\n", numRoad, d[idEnd], maxHappy, maxAvgHap);
    for(int i = path.size() - 1; i >= 0; --i)
    {
        id = path[i];
        cout << id2city[id];
        if(i > 0)
            cout << "->";
    }

    return 0;
}




/*
10:30
11:30
15:37
16:56
*/

/*
Sample Input:
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1
Sample Output:
3 3 195 97
HZH->PRS->ROM
*/