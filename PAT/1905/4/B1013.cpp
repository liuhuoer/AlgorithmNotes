#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = 100001;

int prime[10005];

/*
//version1
bool isPrime(int n)
{
    if(n <= 1)
        return false;
    int sqr = sqrt(n);
    for(int i = 2; i <= sqr; ++i)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

void getPrime(int m)
{
    int sqr;
    int count = 0;
    for(int i = 1; i <= MAXN; ++i)
    {
        if(isPrime(i))
        {
            prime[count++] = i;
            if(count >= m)
                break;
        }
    }
}
*/
//version2
int p[MAXN] = {0};
void getPrime(int m)
{
    int count = 0;
    for(int i = 2; i <= MAXN; ++i)
    {
        if(p[i] == false)
        {
            prime[count++] = i;
            for(int j = i + i; j <= MAXN; j += i)
                p[j] = true;
            if(count >= m)
                break;
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    getPrime(m);

    int count = 0;
    for(int i = n - 1; i <= m - 1; ++i)
    {
        printf("%d", prime[i]);
        ++count;
        if(count % 10 == 0 || count == m - n + 1)
            printf("\n");
        else
        {
            printf(" ");
        }
        
    }

    return 0;
}




/*
20:07
20:40
*/


/*
# test case1:
5 27

# result1:
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/