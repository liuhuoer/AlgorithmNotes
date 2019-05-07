#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int m, n, value;
    scanf("%d", &m);
    int coupons[105], products[105];
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
    int sum = 0;
    for(int i = 0; i < n && i < m && coupons[i] < 0 && products[i] < 0; ++i)
        sum += coupons[i] * products[i];
    
    for(int i = m - 1, j = n - 1; i >= 0 && j >= 0 && coupons[i] > 0 && products[j] > 0; --i, --j)
        sum += coupons[i] * products[i];
    printf("%d", sum);
     
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