#include <cstdio>

int input[105];
int n;

void swap(int a, int b)
{
    int t = input[a];
    input[a] = input[b];
    input[b] = t;
}

int check()
{
    for(int i = 0; i < n; ++i)
    {
        if(input[i] != i)
            return i;
    }
    return n + 1;
}

int main()
{
    scanf("%d", &n);
    int a, b;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &input[i]);
        if(input[i] == 0)
            a = i;
    }
    int num = 0;
    for(int i = 0; i < n; ++i)
    {
        if(input[i] == a)
        {
            b = i;
            i = -1;
            swap(a, b);
            ++num;
            a = b;
        }
        if(input[0] == 0 && a == 0)
        {
            int tmp = check();
            if(tmp == n + 1)
                break;
            else
            {
                swap(a, tmp);
                ++num;
                a = tmp;
            }
        }
    }
    printf("%d\n", num);

    return 0;
}



/*
8:51
9:52
*/

/*
# test case1:
10 3 5 7 2 6 4 9 0 8 1
*/