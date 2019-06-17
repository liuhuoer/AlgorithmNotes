#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const int MAXN = 100010; 
const double INF = 1e12;
int N, MINIDEP = MAXN, MINIDEPNUM = 0;
double P, R, MINIPRICE = INF;

struct Node
{
    int depth;
    vector<int> children;
} dics[MAXN];

void DFS(int root, int depth)
{
    dics[root].depth = depth;
    if(dics[root].children.size() == 0)
    {
        double res = P * pow(1 + R, depth);
        if(res < MINIPRICE)
        {
            MINIPRICE = res;
            MINIDEP = depth;
        }
        return;
    }
    int sz = dics[root].children.size();
    for(int i = 0; i < sz; ++i)
    {
        DFS(dics[root].children[i], depth + 1);
    }
}

void findBiggest()
{
    for(int i = 0; i < N; ++i)
    {
        if(dics[i].depth == MINIDEP && dics[i].children.size() == 0)
            ++MINIDEPNUM;
    }
}

int main()
{
    scanf("%d %lf %lf", &N, &P, &R);
    R /= 100;
    int k, tmp;
    for(int i = 0; i < N; ++i)
    {
        scanf("%d", &k);
        for(int j = 0; j < k; ++j)
        {
            scanf("%d", &tmp);
            dics[i].children.push_back(tmp);
        }
    }
    DFS(0, 0);
    findBiggest();
    printf("%.4lf %d", MINIPRICE, MINIDEPNUM);

    return 0;
}




/*
8:44
9:48
*/

/*
Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0
Sample Output:
1.8362 2
*/