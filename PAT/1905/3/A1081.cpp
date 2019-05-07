# include <cstdio>
# include <algorithm>

using namespace std;

typedef long long ll;

struct Fraction
{
    ll up, down;
};

ll gcd(int a, int b)
{
    return b != 0? gcd(b, a % b) : a;
}

Fraction reduction(Fraction t)
{
    if(t.down < 0)
    {
        t.up = -t.up;
        t.down = -t.down;
    }
    if(t.up == 0)
    {
        t.down = 1;
    }
    int d = gcd(abs(t.up), abs(t.down)); if(d != 1)
    {
        t.up /= d;
        t.down /= d;
    }
    return t;
}


Fraction add(Fraction a, Fraction b)
{
    Fraction sum;
    sum.up = a.up * b.down + b.up * a.down;
    sum.down = a.down * b.down;
    return reduction(sum);
}

void showFraction(Fraction a)
{
    a = reduction(a);
    if(a.down == 1)
        printf("%lld\n", a.up);
    else if(abs(a.up) > a.down)
        printf("%lld %lld/%lld\n", a.up/a.down, abs(a.up) % a.down, a.down);
    else
        printf("%lld/%lld\n", a.up, a.down);
}

int main()
{
    int n;
    scanf("%lld", &n);
    Fraction tmp, sum;
    sum.up = 0, sum.down = 1;
    for(int i = 0; i < n; ++i)
    {
        scanf("%lld/%lld", &tmp.up, &tmp.down);
        sum = add(sum, tmp);
    }
    showFraction(sum);

    return 0;
}




/*
16:09
16:51
*/

/*
# test case1:
5
2/5 4/15 1/30 -2/60 8/3

# result1:
3 1/3

# test case2:
2
4/3 2/3

# result2:
2

# test case3:
3
1/3 -1/6 1/8

# result3:
7/24

*/