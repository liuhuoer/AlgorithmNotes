#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

int main()
{
    int m, n, value;
    scanf("%d", &m);
    int coupons[100010], products[100010];
    for(int i = 0; i < m; ++i)
    {
        scanf("%d", &coupons[i]);
    }
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &products[i]);
    }
    sort(coupons, coupons + m);
    sort(products, products + n);
    LL sum = 0;
    for(int i = 0; i < n && i < m && coupons[i] < 0 && products[i] < 0; ++i)
        sum += (LL)coupons[i] * products[i];
    
    for(int i = m - 1, j = n - 1; i >= 0 && j >= 0 && coupons[i] > 0 && products[j] > 0; --i, --j)
        sum += (LL)coupons[i] * products[j];
    printf("%lld\n", sum);
     
    return 0;
}

/*
20:54
21:40
*/

/*
# test case1:
4
1 2 4 -1
4
7 6 -2 -3
*/