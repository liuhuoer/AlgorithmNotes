#include <iostream>
#include <vector>

using namespace std;

int N, K, P, maxfacsum;
vector<int> fac, tmp, ans;

int power(int t)
{
    int res = 1, tmp = P;
    while(tmp > 0)
    {
        res *= t;
        --tmp;
    }
    return res;
}

int init()
{
    int i = 0, sum = 0;
    for(;sum <= N; ++i)
    {
        sum = power(i);
        fac.push_back(sum);
    }
    return --i;
}

void DFS(int index, int numK, int sum, int facsum)
{
    if(numK == K && sum == N)
    {
        if(facsum > maxfacsum)
        {
            maxfacsum = facsum;
            ans = tmp;
        }
        return;
    }
    if(numK > K || sum > N)
        return;
    if(index >= 1)
    {
        tmp.push_back(index);
        DFS(index, numK + 1, sum + fac[index], facsum + index);
        tmp.pop_back();
        DFS(index - 1, numK, sum, facsum);
    }
}

int main()
{
    // input
    cin >> N >> K >> P;
    // init vector<int> fac
    int index = init();
    // DFS
    DFS(index, 0, 0, 0);
    // output
    if(ans.size() == 0)
    {
        printf("Impossible");
    }
    else
    {
        printf("%d = %d^%d", N, ans[0], P);
        int sz = ans.size();
        for(unsigned i = 1; i < ans.size(); ++i)
        {
            printf(" + %d^%d", ans[i], P);
        }
    }
    
    return 0;
}




/*
21:00
22:35
*/

/*
Sample Input 1:
169 5 2
Sample Output 1:
169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2
Sample Input 2:
169 167 3
Sample Output 2:
Impossible
*/