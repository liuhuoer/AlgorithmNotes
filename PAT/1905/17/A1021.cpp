#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

const int MAXN = 10005;
int n, father[MAXN];

void init()
{
    for(int i = 1; i <= n; ++i)
    {
        father[i] = i;
    }
}

int findFather(int x)
{
    int a = x;
    while(father[x] != x)
    {
        x = father[x];
    }
    
    while(father[a] != a)
    {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void nion(int a, int b)
{
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa != fb)
        father[fa] = fb;
}

int block()
{
    bool isRoot[MAXN] = {false};
    for(int i = 1; i <= n; ++i)
    {
        isRoot[findFather(i)] = true;
    }

    int num = 0;
    for(int i = 1; i <= n; ++i)
        num += isRoot[i];

    return num;
}

int heightMax = 0;
//vector<int> tmp, res;
set<int> tmp, res;
vector<int> G[MAXN];

void DFS(int no, int height, int pre)
{
    if(height > heightMax)
    {
        heightMax = height;
        tmp.clear();
        tmp.insert(no);
    }else if(height == heightMax){
        tmp.insert(no);
    }
    //tmp.push_back(no);

    for(int i = 0; i < G[no].size(); ++i)
    {
        if(G[no][i] == pre)
            continue;
        else
            DFS(G[no][i], height + 1, no);
    }
}

int main()
{
    scanf("%d", &n);
    init();
    int a, b;
    for(int i = 1; i < n; ++i)
    {
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
        nion(a, b);
    }
    int k = block();
    if(k != 1)
        printf("Error: %d components\n", k);
    else{
        DFS(1, 1, -1);
        res.insert(tmp.begin(), tmp.end());
        //res = tmp;
        //DFS(res[0], 1, -1);
        DFS(*(res.begin()), 1, -1);
        res.insert(tmp.begin(), tmp.end());
        /*
        for(int i = 0; i < tmp.size(); ++i)
        {
            res.push_back(tmp[i]);
        }
        */
        //sort(res.begin(), res.end());
        for(auto beg = res.begin(); beg != res.end(); ++beg)
            printf("%d\n", *(beg));
        /*
        printf("%d\n", res[0]);
        for(int i = 1; i < res.size(); ++i)
        {
            if(res[i] != res[i - 1])
                printf("%d\n", res[i]);
        }
        */
    }

    return 0;
}



/*
8:42
10:30
12:30
*/

/*
Sample Input 1:
5
1 2
1 3
1 4
2 5
Sample Output 1:
3
4
5
Sample Input 2:
5
1 3
1 4
2 5
3 4
Sample Output 2:
Error: 2 components
*/