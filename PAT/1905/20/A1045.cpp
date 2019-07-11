#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXV = 205;
const int MAXN = 10010;

int main()
{
    int n, m;
    int Hash[MAXV];
    memset(Hash, -1, sizeof(Hash));
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 0, x; i < m; ++i)
    {
        scanf("%d", &x);
        Hash[x] = i;
    }
    int L, num = 0;
    int A[MAXN];
    scanf("%d", &L);
    for(int i = 0, x; i < L; ++i)
    {
        scanf("%d", &x);
        if(Hash[x] >= 0)
            A[num++] = Hash[x];
    }
    int ans = 0, dp[MAXN];
    for(int i = 0; i < num; ++i)
    {
        dp[i] = 1;
        for(int j = 0; j < i; ++j)
        {
            if(A[j] <= A[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);

    return 0;
}




/*
16:30
17:15
*/


/*
Sample Input:
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6
Sample Output:
7
*/