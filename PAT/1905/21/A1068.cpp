#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 10010;
const int MAXC = 105;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int w[MAXN];
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &w[i]);
    }
    sort(w, w + n, cmp);
    int dp[MAXC] = {0};
    bool node[MAXN][MAXC] = {false};
    for(int i = 0; i < n; ++i)
    {
        for(int v = m; v >= w[i]; --v)
        {
            if(dp[v] <= dp[v - w[i]] + w[i])
            {
                dp[v] = dp[v - w[i]] + w[i];
                node[i][v] = true;
            }else{
                node[i][v] = false;
            }
        }
    }
    bool flag[MAXN] = {false};
    if(dp[m] != m)
        printf("No Solution\n");
    else{
        int v = m, num = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            if(node[i][v] == true)
            {
                ++num;
                flag[i] = true;
                v -= w[i];
            }else{
                flag[i] = false;
            }
        }
        for(int i = n - 1; i >= 0; --i)
        {
            if(flag[i] == true)
            {
                printf("%d", w[i]);
                --num;
                if(num > 0)
                    printf(" ");

            }
        }
    }

    return 0;
}

/*
18:30
19:32
*/


/*
Sample Input 1:
8 9
5 9 8 7 2 3 4 1
Sample Output 1:
1 3 5
Sample Input 2:
4 8
7 2 4 3
Sample Output 2:
No Solution
*/