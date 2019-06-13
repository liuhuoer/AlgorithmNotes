#include <iostream>
#include <queue>

using namespace std;

int M, N, L, T;
int pixel[1286][128][61];
bool inq[1286][128][61] = {false};
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};

struct Node
{
    int x, y, z;
};

bool check(int x, int y, int z)
{
    if(x >= M || x < 0 || y >= N || y < 0 || z >= L || z < 0)
        return false;
    if(pixel[x][y][z] == 0 || inq[x][y][z] == true)
        return false;
    return true;
}

int BFS(int x, int y, int z)
{
    int tot = 0;
    Node tmp;
    tmp.x = x, tmp.y = y, tmp.z = z;
    queue<Node> qn;
    qn.push(tmp);
    inq[x][y][z] = true;
    while(!qn.empty())
    {
        Node nod = qn.front();
        qn.pop();
        ++tot;
        for(int i = 0; i < 6; ++i)
        {
            int newx = nod.x + X[i];
            int newy = nod.y + Y[i];
            int newz = nod.z + Z[i];
            if(check(newx, newy, newz))
            {
                tmp.x = newx, tmp.y = newy, tmp.z = newz;
                qn.push(tmp);
                inq[newx][newy][newz] = true;
            }
        }
    }
    if(tot < T)
        return 0;
    else
        return tot;
}

int main()
{
    cin >> M >> N >> L >> T;
    for(int z = 0; z < L; ++z)
    {
        for(int x = 0; x < M; ++x)
        {
            for(int y = 0; y < N; ++y)
            {
                cin >> pixel[x][y][z];
            }
        }
    }
    int res = 0;
    for(int z = 0; z < L; ++z)
    {
        for(int x = 0; x < M; ++x)
        {
            for(int y = 0; y < N; ++y)
            {
                if(pixel[x][y][z] == 1 && inq[x][y][z] == false)
                    res += BFS(x, y, z);
            }
        }
    }
    printf("%d\n", res);

    return 0;
}




/*
22:41
01:00
*/

/*
Sample Input:
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0
Sample Output:
26
*/
