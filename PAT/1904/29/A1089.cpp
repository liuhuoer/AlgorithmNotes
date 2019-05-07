#include <cstdio>
#include <algorithm>

using namespace std;

int origin[105];
int backup[105];
int now[105];
int n;

bool isSame()
{
    for(int i = 0; i < n; ++i)
    {
        if(backup[i] != now[i])
        {
            return false;
        }
    }
    return true;
}

void show(int* a)
{
    for(int i = 0; i < n; ++i)
    {
        printf("%d", a[i]);
        if(i < n - 1)
            printf(" ");
    }
    printf("\n");
}

bool isInsertSort()
{
    int count = 0;
    bool flag = false;
    for(int i = 1; i < n; ++i)
    {
        if(i != 1 && isSame())
            flag = true;
        int tmp = backup[i], j = i;
        while(j > 0 && backup[j - 1] > tmp)
        {
            backup[j] = backup[j - 1];
            --j;
        }
        backup[j] = tmp;

        if(flag)
            return true;
    }
    return false;
}

void mergeSort()
{
    int size = 2;
    bool flag = false;
    for(int size = 2; size / 2 <= n; size *= 2)
    {
        if(size != 2 && isSame())
            flag = true;
        for(int i = 0; i < n; i += size)
            sort(backup + i, backup + min(i + size, n));
        if(flag == true)
            return;
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &origin[i]);
        backup[i] = origin[i];
    }
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &now[i]);
    }
    if(isInsertSort())
    {
        printf("Insert Sort\n");
        show(backup);
    }
    else{
        printf("Merge Sort\n");
        for(int i = 0; i < n; ++i)
            backup[i] = origin[i];
        mergeSort();
        show(backup);
    }

    return 0;
}




/*
10:38
12:24
*/

/*
# test case1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0

# test case2:
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6

*/