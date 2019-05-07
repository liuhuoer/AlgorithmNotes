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
    return b == 0 ? a : gcd(b, a % b);
}

Fraction reduction(Fraction a)
{
    if(a.down < 0)
    {
        a.up = -a.up;
        a.down = -a.down;
    }
    if(a.up == 0)
        a.down = 1;
    int d = gcd(abs(a.up), abs(a.down));
    if(d != 1)
    {
        a.up /= d;
        a.down /= d;
    }
    return a;
}

Fraction add(Fraction a, Fraction b)
{
    Fraction sum;
    sum.up = a.up * b.down + b.up * a.down;
    sum.down = a.down * b.down;
    return reduction(sum);
}

Fraction minu(Fraction a, Fraction b)
{
    Fraction res;
    res.up = a.up * b.down - b.up * a.down;
    res.down = a.down * b.down;
    return reduction(res);
}

Fraction multi(Fraction a, Fraction b)
{
    Fraction res;
    res.up = a.up * b.up;
    res.down = a.down * b.down;
    return reduction(res);
}

Fraction divite(Fraction a, Fraction b)
{
    Fraction res;
    res.up = a.up * b.down;
    res.down = b.up * a.down;
    return reduction(res);
}

void show(Fraction a)
{

    a = reduction(a);
    if(a.up < 0)
        printf("( ");
    if(a.down == 1)
        printf("%lld", a.up);
    else if(abs(a.up) > a.down)
        printf("%lld %lld/%lld", a.up / a.down, abs(a.up) % a.down, a.down);
    else
        printf("%lld/%lld", a.up, a.down);
    if(a.up < 0)
        printf(" )");
}

int main()
{
    Fraction a, b;
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);

    show(a);
    printf(" + ");
    show(b);
    printf(" = ");
    show(add(a, b));
    printf("\n");

    show(a);
    printf(" - ");
    show(b);
    printf(" = ");
    show(minu(a, b));
    printf("\n");

    show(a);
    printf(" * ");
    show(b);
    printf(" = ");
    show(multi(a, b));
    printf("\n");

    show(a);
    printf(" / ");
    show(b);
    printf(" = ");
    if(b.up == 0)
        printf("Inf");
    else
        show(divite(a, b));
    printf("\n");


    return 0;
}




/*
16:54
18:04
*/

/*
# test case1:
2/3 -4/2

# result1:
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)

# test case2:
5/3 0/6

# result2:
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf

*/