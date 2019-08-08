#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;

int main()
{
    char str[MAXN];
    scanf("%s", &str);
    int len = strlen(str);
    int numP[MAXN], numT = 0, numAns = 0;
    memset(numP, 0, sizeof(numP));
    for(int i = 0; i < len; ++i)
    {
        if(i > 0)
            numP[i] = numP[i - 1];

        if(str[i] == 'P')
            ++numP[i];
    }
    for(int i = len - 1; i >= 0; --i)
    {
        if(str[i] == 'T')
            ++numT;
        
        if(str[i] == 'A')
            numAns = (numAns + numP[i] * numT) % MOD;
    }
    printf("%d\n", numAns);

    return 0;
}




/*
19:26
20:01
*/

/*
# test case1:
APPAPT

# result1:
2
*/