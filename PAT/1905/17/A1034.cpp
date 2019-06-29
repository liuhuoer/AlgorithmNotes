#include <iostream>
#include <string>
#include <map>

using namespace std;

const int MAXN = 2010; 
int n, k, numPerson = 0;
map<string, int> str2id, gang;
map<int, string> id2str;
bool vis[MAXN] = {false};
int W[MAXN] = {0}, G[MAXN][MAXN] = {0};

int change(string str)
{
    if(str2id.find(str) != str2id.end())
        return str2id[str];
    else
    {
        str2id[str] = numPerson;
        id2str[numPerson] = str;
        return numPerson++;
    }
}

void DFS(int now, int & head, int & sNum, int & sValue)
{
    ++sNum;
    vis[now] = true;
    if(W[now] > W[head])
        head = now;

    for(int i = 0; i < numPerson; ++i)
    {
        if(G[now][i] > 0)
        {
            sValue += G[now][i];
            G[now][i] = G[i][now] = 0;
            if(vis[i] == false)
                DFS(i, head, sNum, sValue);
        }
    }
}

void DFStrave()
{
    for(int i = 0; i < numPerson; ++i)
    {
        if(vis[i] == false)
        {
            int sNum = 0, sValue = 0, head = i;
            DFS(i, head, sNum, sValue);
            if(sNum > 2 && sValue > k)
                gang[id2str[head]] = sNum;
        }
    }
}

int main()
{
    cin >> n >> k;
    string str1, str2;
    int tmpk;
    for(int i = 0; i < n; ++i)
    {
        cin >> str1 >> str2 >> tmpk;
        int id1 = change(str1);
        int id2 = change(str2);
        W[id1] += tmpk;
        W[id2] += tmpk;
        G[id1][id2] += tmpk;
        G[id2][id1] += tmpk;
    }
    DFStrave();
    cout << gang.size() << endl;
    for(auto beg = gang.begin(); beg != gang.end(); ++beg)
        cout << beg->first << " " << beg->second << endl;

    return 0;
}



/*
15:35
*/

/*
Sample Input 1:
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:
2
AAA 3
GGG 3
Sample Input 2:
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:
0
*/