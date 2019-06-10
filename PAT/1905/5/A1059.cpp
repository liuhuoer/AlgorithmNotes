# include <cstdio>
# include <cmath>
# include <vector>
using namespace std;

const int MAXN = 100005;
int prime[MAXN] = {0};

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

void FindPrime()
{
    int count = 0;
    for(int i = 0; i < MAXN; ++i)
    {
        if(isPrime(i))
            prime[count++] = i;
    }
}

struct Factor{
    int num, count;
}fac[10];

// version2
int main()
{
    int n; 
    scanf("%d", &n);
    FindPrime();
    printf("%d=", n);
    int count = 0;
    if(n <= 1)
        printf("%d", n);
    else{
        int sqr = sqrt(n);
        for(int i = 0; prime[i] <= sqr; ++i)
        {
            if(n % prime[i] == 0)
            {
                fac[count].num = prime[i];
                fac[count].count = 1;
                n /= prime[i];
                while(n % prime[i] == 0)
                {
                    ++fac[count].count;
                    n /= prime[i];
                }
                ++count;
            }
            if(n == 1)
                break;
        }
        if(n != 1)
        {
            fac[count].num = n;
            fac[count++].count = 1;
        }
        for(int i = 0; i < count; ++i)
        {
            if(i > 0)
                printf("*");
            printf("%d", fac[i]);
            if(fac[i].count > 1)
                printf("^%d", fac[i].count);
        }
    }

    return 0;
}

// version1
/*
int main()
{
    long n;
    scanf("%ld", &n);
    printf("%ld=", n);
    vector<int> vi;
    if(n <= 1)
        printf("%ld\n", n);
    else{
        //get all factors of n
        int sqr = sqrt(n);
        for(int i = 2; i <= sqr; ++i)
        {
            if(n % i == 0)
            {
                vi.push_back(i);
                n /= i;
                --i;
            }
        }
        if(n != 1)
            vi.push_back(n);
        //output
        if(vi.size() == 0)
            printf("%ld\n", n);
        else{
            int count = 1;
            printf("%d", vi[0]);
            for(int i = 1; i < vi.size(); ++i)
            {
                if(vi[i] != vi[i - 1])
                {
                    if(count == 1)
                        printf("*%d", vi[i]);
                    else
                    {
                        printf("^%d*%d", count, vi[i]);
                        count = 1;
                    }
                }
                else
                {
                    ++count;
                    if(i == vi.size() - 1)
                        printf("^%d", count);
                }
            }
        }
    }

    return 0;
}

*/



/*
15:05
15:45
*/

/*
# test case1:
97532468

# result1:
97532468=2^2*11*17*101*1291

# test case2:
1

# result2:
1

# test case3:
7

# result3:
7

# test case4:
8

# result4:
8=2^3

# test case5:
10

# result5:
10=2*5
*/