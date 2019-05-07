#include <cstdio>
#include <algorithm>
using namespace std;

struct Mooncake
{
    Mooncake()
    {
        num = 0, cost = 0, price = 0;
    }
    int num;
    float cost;
    float price;
};

bool cmp(Mooncake a, Mooncake b)
{
    return a.price > b.price;
}

int main()
{
    Mooncake mc[505];
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &mc[i].num);
    }
    for(int i = 0; i < n; ++i)
    {
        scanf("%f", &mc[i].cost);
        mc[i].price = mc[i].cost / mc[i].num;
    }
    sort(mc, mc + n, cmp);
    float res = 0.0;
    for(int i = 0; i < n && m > 0; ++i)
    {
        if(mc[i].num > m)
        {
            res += mc[i].price * m;
            m -= m;
            break;
        }
        else
        {
            res += mc[i].cost;
            m -= mc[i].num;
        }
    }
    printf("%.2f", res);

    return 0;
}





/*
9:08
9:46
*/


/*
# test case1:
3 20
18 15 10
75 72 45
*/