#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXV = 205;
const int MAXN = 10010;
int A[MAXV], B[MAXN], dp[MAXV][MAXN];

int main()
{
    int n, m, l;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i)
    {
        scanf("%d", &A[i]);
    }
    scanf("%d", &l);
    for(int i = 1; i <= l; ++i)
    {
        scanf("%d", &B[i]);
    }

    for(int i = 0; i <= m; ++i)
    {
        dp[i][0] = 0;
    }
    for(int i = 0; i <= l; ++i)
    {
        dp[0][i] = 0;
    }
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= l; ++j)
        {
            int maxPre = max(dp[i - 1][j], dp[i][j - 1]);
            if(A[i] == B[j])
            {
                dp[i][j] = maxPre + 1;
            }else{
                dp[i][j] = maxPre;
            }
        }
    }
    printf("%d", dp[m][l]);

    return 0;
}

/*
17:21
18:11
*/

/*
Sample Input:
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6
Sample Output:
7
*/