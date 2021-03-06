#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

char name[40010][5];

int main()
{
    vector<int> vs[2505];
    int n, m;
    scanf("%d %d", &n, &m);
    int num, sId, cId;
    for(int i = 0; i < n; ++i)
    {
        scanf("%s %d", name[i], &num);
        while(num--)
        {
            scanf("%d", &cId);
            vs[cId].push_back(i);
        }
    }
    for(int i = 0; i < m; ++i)
    {
        sort(vs[i].begin(), vs[i].end());
        printf("%d %d\n", i + 1, vs[i].size());
        for(int j = 0; j < vs[i].size(); ++j)
            printf("%s\n", name[vs[i][j]]);
    }

    return 0;
}




/*
13:25
13:55
*/

/*
# test case1:
10 5
ZOE1 2 4 5
ANN0 3 5 2 1
BOB5 5 3 4 2 1 5
JOE4 1 2
JAY9 4 1 2 5 4
FRA8 3 4 2 5
DON2 2 4 5
AMY7 1 5
KAT3 3 5 4 2
LOR6 4 2 4 1 5

# result1: P236
*/