#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    float sum = 0.0;
    //version2
    float key;
    for(int i = 0; i < n; ++i)
    {
        scanf("%f", &key);
        sum += key * (i + 1) * (n - i);
    }
    /*
    //version1
    //two pointer
    float value[105];
    for(int i = 0; i < n; ++i)
    {
        scanf("%f", &value[i]);
    }
    float sub_sum;
    for(int i = 0; i != n; ++i)
    {
        sub_sum = 0.0;
        for(int j = i; j != n; ++j)
        {
            sub_sum += value[j];
            sum += sub_sum;
        }
    }
    */
    printf("%.2f\n", sum);

    
    return 0;
}




/*
8:49
9:24
*/

/*
# test case1:
4
0.1 0.2 0.3 0.4

# result1:
5.00
*/