#include <cstdio>
#include <algorithm>

using namespace std;

int n, p;
int input[105];

int binary_search(int i, long long x)
{
    if(input[n - 1] <= x)
        return n;
    int left = i + 1, right = n - 1, mid;
    while(left < right)
    {
        mid = (left + right) / 2;
        if(input[mid] <= x)
            left = mid + 1;
        else
        {
            right = mid;
        }
        
    }
    return left;
}

int main()
{
    scanf("%d %d", &n, &p);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &input[i]);
    }
    sort(input, input + n);
    int res = 1;
    for(int i = 0; i < n; ++i)
    {
        //int j = upper_bound(input + i + 1, input + n, (long long)input[i] * p) - input;
        int j = binary_search(i + 1, input[i] * p);
        res = max(res, j - i);
    }
    printf("%d", res);

    return 0;
}


/*
8:48
10:33
*/

/*
# test case1:
10 8
2 3 20 4 5 1 6 7 8 9
*/