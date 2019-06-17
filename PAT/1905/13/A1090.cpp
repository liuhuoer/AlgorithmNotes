#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 100010;
int N, maxNumBros;
double P, R, maxRes = 0.0;

struct Node
{
    int key;
    vector<int> children;
} dics[MAXN];

void DFS(int root, int depth)
{
    double res = 0.0;
    if(dics[root].children.size() == 0)
    {
        res = P * pow((1 + R), depth);
        if(res > maxRes)
        {
            maxRes = res;
            maxNumBros = 1;
            return;
        }else if(res == maxRes){
            ++maxNumBros;
        }
    }
    int sz = dics[root].children.size();
    for(int i = 0; i < sz; ++i)
    {
        DFS(dics[root].children[i], depth + 1);
    }
    return;
}

int main()
{
    scanf("%d %lf %lf", &N, &P, &R);
    R /= 100;

    int k, root;
    for(int i = 0; i < N; ++i)
    {
        scanf("%d", &k);
        if(k != -1)
            dics[k].children.push_back(i);
        else
            root = i;
    }
    DFS(root, 0);
    printf("%.2f %d", maxRes, maxNumBros);

    return 0;
}




/*
21:55
22:52
*/

/*
Sample Input:
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
Sample Output:
1.85 2
*/