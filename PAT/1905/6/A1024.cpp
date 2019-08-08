# include <cstdio>
# include <cstring>
# include <string>
# include <iostream>
using namespace std;

struct Big
{
    Big()
    {
        len = 0;
        memset(num, 0, sizeof(num));
    }
    Big(const string& a)
    {
        memset(num, 0, sizeof(num));
        len = a.size();
        for(int i = 0; i < len; ++i)
            num[i] = a[len - 1 - i] - '0';
    }
    int len;
    int num[1000];
};

Big add(Big a, Big b)
{
    Big c;
    int up = 0;
    for(int i = 0; i < a.len || i < b.len; ++i)
    {
        int tmp = up + a.num[i] + b.num[i];
        c.num[c.len++] = tmp % 10;
        up = tmp / 10;
    }
    if(up != 0)
        c.num[c.len++] = up;
    return c;
}

Big reverse(Big a)
{
    Big c;
    c.len = a.len;
    for(int i = 0; i < a.len; ++i)
    {
        c.num[i] = a.num[a.len - 1 - i];
    }
    return c;
}

bool check(Big a)
{
    for(int i = 0; i <= a.len / 2; ++i)
    {
        if(a.num[i] != a.num[a.len - 1 - i])
            return false;
    }
    return true;
}

void printBig(Big a)
{
    for(int i = a.len - 1; i >= 0; --i)
    {
        printf("%d", a.num[i]);
    }
    printf("\n");
}

int main()
{
    string str1;
    int k;
    cin >> str1 >> k;
    Big big1(str1), big2;
    int i;
    for(i = 0; i < k && check(big1) == false; ++i)
    {
        big2 = big1;
        big2 = reverse(big2);
        big1 = add(big1, big2);
    }
    printBig(big1);
    printf("%d\n", i);

    return 0;
}




/*
21:48
22:53
*/

/*
# test case1:
67 3

# result1:
484
2

# test case2:
69 3

# result2:
1353
3
*/