#include <cstdio>
#include <algorithm>

using namespace std;

int value[100005];

int main()
{
    int n;
    long long key;
    scanf("%d %ld", &n, &key);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &value[i]);
    }
    sort(value, value + n);
    int i = 0, j = 0, len = 0;
    while(i < n && j < n)
    {
        for(; j < n && value[j] <= value[i] * key; ++j)
        {
            len = max(len, j - i + 1);
        }
        ++i;
    }
    printf("%d\n", len);

    return 0;
}



/*
16:46
17:08
*/


/*
# test case1:
10 8
2 3 20 4 5 1 6 7 8 9
*/