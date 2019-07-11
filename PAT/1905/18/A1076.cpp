#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 1010;

struct Node
{
    int id;
    int layer;
};

bool vis[MAXN];
vector<Node> G[MAXN];

int BFS(int now, int l)
{
    int followern = 0;
    Node user;
    user.id = now;
    user.layer = 0;
    queue<Node> qn;
    qn.push(user);
    vis[now] = true;
    while(!qn.empty())
    {
        Node toptmp = qn.front();
        qn.pop();
        for(int i = 0; i < G[toptmp.id].size(); ++i)
        {
            Node next = G[toptmp.id][i];
            next.layer = toptmp.layer + 1;
            if(vis[next.id] == false && next.layer <= l)
            {
                qn.push(next);
                vis[next.id] = true;
                ++followern;
            }
        }
    }

    return followern;
}

int main()
{
    int n, l;
    Node user;
    scanf("%d %d", &n, &l);
    for(int i = 1; i <= n; ++i)
    {
        user.id = i;
        int subn;
        scanf("%d", &subn);
        for(int j = 0; j < subn; ++j)
        {
            int follow;
            scanf("%d", &follow);
            G[follow].push_back(user);
        }
    }

    int queryn;
    scanf("%d", &queryn);
    for(int i = 0; i < queryn; ++i)
    {
        int tmp;
        memset(vis, false, sizeof(vis));
        scanf("%d", &tmp);
        int res = BFS(tmp, l);
        printf("%d\n", res);
    }

    return 0;
}




/*
8:31
9:50
*/

/*
Sample Input:
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
Sample Output:
4
5
*/