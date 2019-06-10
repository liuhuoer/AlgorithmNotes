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
    int num[30];
};

Big add(Big a, Big b)
{
    Big c;
    int up = 0, i;
    for(i = 0; i < a.len; ++i)
    {
        up = up + a.num[i] + b.num[i];
        c.num[i] = up % 10;
        up /= 10;
    }
    while(up != 0)
    {
        c.num[i++] = up % 10;
        up /= 10;
    }
    c.len = i;
    return c;
}

Big reverse(Big a)
{
    Big c;
    for(int i = 0; i < a.len; ++i)
    {
        c.num[i] = a.num[a.len - 1 - i];
    }
    return c;
}

bool check(Big a)
{
    for(int i = 0; i < a.len / 2; ++i)
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
}

int main()
{
    string str1;
    int k;
    cin >> str1 >> k;
    Big big1(str1), big2;
    int i;
    for(i = 0; i < k; ++i)
    {
        big2 = reverse(big1);
        big1 = add(big1, big2);
        if(check(big1))
        {
            ++i;
            break;
        }
    }
    printBig(big1);
    printf("\n%d", i);

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