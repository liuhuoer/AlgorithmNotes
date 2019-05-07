#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp_d(int a, int b)
{
    return a > b;
}

int toNum(int* a, int len)
{
    int res = 0;
    for(int i = 0; i < len; ++i)
    {
        res = res * 10 + a[i];
    }
    return res;
}

void toArr(int* value, int key)
{
    int count = 0;
    do{
        value[count++] = key % 10;
        key /= 10;
    }while(key);
}

int main()
{
    int key;
    scanf("%d", &key);
    int value[5], res = -1, count;
    int a, b;
    while(res != 6174 && res != 0)
    {
        toArr(value, key);

        sort(value, value + 4, cmp_d);
        a = toNum(value, 4);
        sort(value, value + 4);
        b = toNum(value, 4);
        res = a - b;
        printf("%04d - %04d = %04d\n", a, b, res);
        key = res;
    }

    return 0;
}




/*
23:15
23:55
*/

/*
# test case1:
6767

# result1:
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174

# test case2:
2222

# result2:
2222 - 2222 = 0
*/