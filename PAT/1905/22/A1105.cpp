#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 101;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int N;
    scanf("%d", &N);
    int num[MAXN];
    for(int i = 0; i < N; ++i)
    {
        scanf("%d", &num[i]);
    }
    if(N == 1)
    {
        printf("%d", num[0]);
        return 0;
    }

    sort(num, num + N, cmp);

    int m = (int)ceil(sqrt(1.0 * N));
    while(N % m != 0)
        ++m;
    //for(; N % m != 0; ++m);
    int n = N / m;
    int L = 1, R = n, U = 1, D = m;
    int now = 0, i = 1, j = 1, ans[MAXN][MAXN];
    while(now < N)
    {
        for(; now < N && j < R; ++j)
            ans[i][j] = num[now++];
        for(; now < N && i < D; ++i)
            ans[i][j] = num[now++];
        for(; now < N && j > L; --j)
            ans[i][j] = num[now++];
        for(; now < N && i > U; --i)
            ans[i][j] = num[now++];
        ++i, ++j;
        ++L, --R, ++U, --D;
        if(now == N - 1)
            ans[i][j] = num[now++];
    }
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            printf("%d", ans[i][j]);
            if(j < n)
                printf(" ");
            else
                printf("\n");
        }
    }

    return 0;
}


/*
Sample Input:
12
37 76 20 98 76 42 53 95 60 81 58 93
Sample Output:
98 95 93
42 37 81
53 20 76
58 60 76
*/



/*
19:06
20:06
*/