#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 105;
int n;
int origin[MAXN], back[MAXN], aim[MAXN];

void showResult()
{
    for(int i = 1; i <= n; ++i)
    {
        printf("%d", back[i]);
        if(i < n)
            printf(" ");
    }
}

bool isSame()
{
    for(int i = 1; i <= n; ++i)
    {
        if(back[i] != aim[i])
            return false;
    }
    return true;
}

bool insertSort()
{
    bool flag = false;
    for(int i = 2; i <= n; ++i)
    {
        if(i != 2 && isSame())
            flag = true;

        sort(back + 1, back + i + 1);

        if(flag)
            return true;
    }
    return false;
}

void downAdjust(int low, int high)
{
    int i = low, j = 2 * i;
    while(j <= high)
    {
        if(j + 1 <= high && back[j] < back[j + 1])
            j = j + 1;
 
        if(back[i] < back[j])
        {
            swap(back[i], back[j]);
            i = j;
            j = i * 2;
        }else{
            break;
        }
    }
}

void heapSort()
{
    bool flag = false;
    // creat heap
    for(int i = n / 2; i >= 1; --i)
    {
        downAdjust(i, n);
    }
    for(int i = n; i > 1; --i)
    {
        if(i != n && isSame())
            flag = true;
        
        swap(back[1], back[i]);
        downAdjust(1, i - 1);
        if(flag)
        {
            showResult();
            return;
        }
    }

}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &origin[i]);
        back[i] = origin[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &aim[i]);
    }

    if(insertSort())
    {
        printf("Insertion Sort\n");
        showResult();
    }else{
        printf("Heap Sort\n");
        for(int i = 1; i <= n; ++i)
        {
            back[i] = origin[i];
        }
        heapSort();
    }

    return 0;
}




/*
15:51
17:30
*/


/*
Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0
Sample Input 2:
10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9
Sample Output 2:
Heap Sort
5 4 3 1 0 2 6 7 8 9
*/