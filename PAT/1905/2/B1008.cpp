#include <cstdio>

int gcd(int a, int b)
{
    if(0 == b)
        return a;
    else
    {
        return gcd(b, a % b);
    }
    
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[105];
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    int tmp, pos, next;
    m = m % n;
    if(m != 0)
    {
        int d = gcd(n, m);
        for(int i = n - m; i <= (n - m) + d - 1; ++i)
        {
            tmp = a[i];
            pos = i;
            next = -1;
            do{
                next = (pos - m + n) % n;
                if(next != i)
                    a[pos] = a[next];
                else
                    a[pos] = tmp;
                pos = next;
            }while(next != i);
        }
    }
    for(int i = 0; i < n; ++i)
    {
        printf("%d", a[i]);
        if(i != n - 1)
            printf(" ");
    }

    return 0;
}




/*
14:31
16:14
*/


/*
# test case1:
6 2
1 2 3 4 5 6

# result1:
5 6 1 2 3 4

*/