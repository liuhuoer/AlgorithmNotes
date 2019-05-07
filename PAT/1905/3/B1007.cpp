# include <cstdio>
# include <cmath>

using namespace std;

bool isPrime(int a)
{
    if(a <= 1)
        return false;
    int n = sqrt(a);
    for(int i = 2; i <= n; ++i)
    {
        if(a % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n, count = 0;    
    scanf("%d", &n);

    for(int i = 3; i + 2 < n; i += 2)
    {
        if(isPrime(i) && isPrime(i + 2))
            ++count;
    }
    printf("%d\n", count);

    return 0;
}




/*
19:50
20:02
*/


/*
# test case1:
20

# result1:
4
*/