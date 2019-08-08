#include <cstdio>
#include <vector>

using namespace std;

const int INF = 0x7fffffff;

vector<int> a, b;

int main()
{
    int n, m;
    scanf("%d", &n);
    int tmp;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    a.push_back(INF);
    scanf("%d", &m);
    for(int i = n + 1; i < n + m + 1; ++i)
    {
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    a.push_back(INF);
    int mid = (n + m - 1) / 2;
    int count = 0, i, j;
    for(i = 0, j = n + 1; count < mid;)
    {
        if(a[i] < a[j])
            ++i;
        else
            ++j;
        ++count;
    }
    if(a[i] < a[j])
        printf("%d\n", a[i]);
    else
        printf("%d\n", a[j]);

    return 0;
}







/*

#include <cstdio>

const int INF = 0x7fffffff;
const int MAXN = 1000010;

int a[MAXN], b[MAXN];

int main()
{
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; ++i)
    {
        scanf("%d", &b[i]);
    }
    a[n] = INF;
    b[m] = INF;
    int mid = (n + m - 1) / 2;
    int count = 0, i, j;
    for(i = 0, j = 0; count < mid;)
    {
        if(a[i] < b[j])
            ++i;
        else
            ++j;
        ++count;
    }
    if(a[i] < b[j])
        printf("%d\n", a[i]);
    else
        printf("%d\n", b[j]);

    return 0;
}
*/




/*
12:27
12:46
*/

/*
# test case1:
4 11 12 13 14
5 9 10 15 16 17
# res1:
13
*/