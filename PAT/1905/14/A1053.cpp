#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> Path;

int n, s;
const int MAXN = 105;
vector<Path> resPath;

struct Node
{
    Node()
    {
        key = 0;
        sumKey = 0;
    }
    int key;
    int sumKey;
    vector<int> children;
    Path parents;
} dics[MAXN];

void DFS(int root, int depth)
{
    dics[root].sumKey += dics[root].key;
    dics[root].parents.push_back(root);
    int sz = dics[root].children.size();
    if(sz == 0)
    {
        if(dics[root].sumKey == s)
        {
            resPath.push_back(dics[root].parents);
        }
        return;
    }
    for(int i = 0; i < sz; ++i)
    {
        dics[dics[root].children[i]].sumKey = dics[root].sumKey;
        dics[dics[root].children[i]].parents = dics[root].parents;
        DFS(dics[root].children[i], depth + 1);
    }
    return;
}

bool cmp(Path a, Path b)
{
    int sza = a.size(), szb = b.size();
    int i = 0;
    for(; i < sza && i < szb; ++i)
    {
        if(dics[a[i]].key > dics[b[i]].key)
            return true;   // a > b
        else if(dics[a[i]].key < dics[b[i]].key)
        {
            return false;
        }
        
    }
    if(i < sza) // a > b
        return true;
    if(i < szb) // a < b
        return false;
}

int main()
{
    int m;
    scanf("%d %d %d", &n, &m, &s);
    int tmpKey;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &tmpKey);
        dics[i].key = tmpKey;
    }
    for(int i = 0, no, k; i < m; ++i)
    {
        scanf("%d %d", &no, &k);
        for(int j = 0, chd; j < k; ++j)
        {
            scanf("%d", &chd);
            dics[no].children.push_back(chd);
        }
    }
    // DFS
    DFS(0, 0);
    // sort
    sort(resPath.begin(), resPath.end(), cmp);
    // output
    for(int i = 0; i < resPath.size(); ++i)
    {
        for(int j = 0; j < resPath[i].size(); ++j)
        {
            printf("%d", dics[resPath[i][j]].key);
            if(j != resPath[i].size() - 1)
                printf(" ");
            else
                printf("\n");
        }
    }

    return 0;
}




/*
20:19
21:20 wo
22:18
*/


/*
Sample Input:
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
Sample Output:
10 5 2 7
10 4 10
10 3 3 6 2
10 3 3 6 2
*/