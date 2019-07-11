#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 101;

int main()
{
    string str;
    getline(cin, str);
    //getLine(cin, str);
    int len = str.size();
    int dp[MAXN][MAXN];
    int ans = 1;
    memset(dp, 0, sizeof(dp));
    //fill(dp[0], dp[0] + MAXN * MAXN, 0);
    for(int i = 0; i < len; ++i)
    {
        dp[i][i] = 1;
        if(i + 1 < len)
        {
            if(str[i] == str[i + 1])
            {
                dp[i][i + 1] = 1;
                ans = 2;
            }
        }
    }

    for(int L = 3; L <= len; ++L)
    {
        for(int i = 0; i + L - 1 < len; ++i)
        {
            int j = i + L - 1;
            if(str[i] == str[j] && dp[i + 1][j - 1] == 1)
            {
                dp[i][j] = 1;
                ans = L;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}




/*
8:42
*/

/*
Sample Input:
Is PAT&TAP symmetric?
Sample Output:
11
*/