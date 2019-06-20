#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1010;
int n, index = 0, value[MAXN], CBT[MAXN] ;

void inOrder(int root)
{
    if(root > n)
        return;
    inOrder(root * 2);
    CBT[root] = value[index++];
    inOrder(root * 2 + 1);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &value[i]);
    }
    sort(value, value + n);
    inOrder(1);
    for(int i = 1; i <= n; ++i)
    {
        printf("%d", CBT[i]);
        if(i != n)
            printf(" ");
    }

    return 0;
}




/*
17:14
18:50
*/


/*
Sample Input 1:
10
1 2 3 4 5 6 7 8 9 0
Sample Output 1:
6 3 8 1 5 7 9 0 2 4
*/