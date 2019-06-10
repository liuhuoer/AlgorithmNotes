#include <stack>
#include <cstdio>

using namespace std;

int main()
{
    int m, n, k, value, nums[1010];
    stack<int> sta;
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 0; i < k; ++i)
    {
        for(int j = 0; j < n; ++j)
            scanf("%d", &nums[j]);

        while(!sta.empty())
            sta.pop();

        int count = 0;
        for(int f = 1; f <= n; ++f)
        {
            sta.push(f);
            if(sta.size() > m)
                break;
            
            while(!sta.empty() && sta.top() == nums[count])
            {
                ++count;
                sta.pop();
            }
        }
        if(count == n)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}




/*
14:25
15:16
*/

/*
# test case1:
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2

# test result1:
YES
NO
NO
YES
NO
*/