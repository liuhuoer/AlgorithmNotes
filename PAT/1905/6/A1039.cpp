#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 26 * 26 * 26 * 10 + 1;
//const int MAXN = 270000;
vector<int> vi[MAXN];

int getId(string a)
{
    int res = 0;
    for(int i = 0; i < 3; ++i)
    {
        res = res * 26 + a[i] - 'A';
    }
    res = res * 10 + a[3] - '0';
    return res;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int cId, numStu, sId;
    string sName;
    for(int i = 0; i < m; ++i)
    {
        scanf("%d %d", &cId, &numStu);
        for(int j = 0; j < numStu; ++j)
        {
            cin >> sName;
            sId = getId(sName);
            vi[sId].push_back(cId);
        }
    }
    string query;
    int queryId;
    while(n--)
    {
        cin >> query;
        queryId = getId(query);
        sort(vi[queryId].begin(), vi[queryId].end());
        cout << query << " " << vi[queryId].size();
        for(int i = 0; i < vi[queryId].size(); ++i)
            cout << " " << vi[queryId][i];
        cout << endl;
    }

    return 0;
}




/*
23:05
23:59
*/

/*
# test case1:
11 5
4 7
BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
1 4
ANN0 BOB5 JAY9 LOR6
2 7
ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
3 1
BOB5
5 9
AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9

# result1:
ZOE1 2 4 5
ANN0 3 1 2 5
BOB5 V5 1 2 3 4 5 
JOE4 1 2
JAY9 4 1 2 4 5
FRA8 3 2 4 5
DON2 2 4 5
AMY7 1 5
KAT3 3 2 4 5
LOR6 4 1 2 4 5
NON9 0
*/