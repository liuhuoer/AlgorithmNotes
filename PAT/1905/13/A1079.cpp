#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int n;
double p, r, res = 0.0;
const int MAXN = 100010;

struct Node
{
    Node()
    {
        num = 0;
    }
    int num;
    vector<int> vn;
} dics[MAXN];

void DFS(int root, int depth)
{
    if(dics[root].vn.size() == 0)
    {
        res += dics[root].num * pow(1 + r, depth);
        return;
    }
    for(int i = 0 ; i < dics[root].vn.size(); ++i)
    {
        DFS(dics[root].vn[i], depth + 1);
    }
}

int main()
{
    scanf("%d %lf %lf", &n, &p, &r);
    r /= 100;
    int k, tmp;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &k);
        if(k == 0)
        {
            scanf("%d", &dics[i].num);
        }
        else
        {
            for(int j = 0; j < k; ++j)
            {
                scanf("%d", &tmp);
                dics[i].vn.push_back(tmp);
            }
        }
        
    }
    DFS(0, 0);
    printf("%.1f\n", res * p);


    return 0;
}



/*
20:31
22:00
*/


/*
Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3
Sample Output:
42.4
*/