#include<cstdio>
#include<cmath>
using namespace std;

const int MAXN = 200005;

bool isPrime(int a)
{
    if(a <= 1)
        return false;
    int sqr = sqrt(a);
    for(int i = 2; i <= sqr; ++i)
    {
        if(a % i == 0)
            return false;
    }
    return true;
}


int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    while(isPrime(m) == false)
        ++m;
    int a, pos[200005] = {0}, posA;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &a);
        posA = a % m;
        if(pos[posA] == false)
        {
            pos[posA] = true;
            printf("%d", posA);
        }
        else{
            int step;
            for(step = 1; step <= m; ++step)
            {
                posA = (posA + step * step) % m;
                if(pos[posA] == false)
                {
                    pos[posA] = true;
                    printf("%d", posA);
                    break;
                }
            }
            if(step == m + 1)
                printf("-");
        }
        
        if(i <= n -1)
            printf(" ");
    }
    

    return 0;
}





/*
21:51
22:28
*/


/*
# test case1:
4 4
10 6 4 15

# result1:
0 1 4 -
*/