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
    Big(string str)
    {
        memset(num, 0, sizeof(num));
        len = str.size();
        for(int i = 0; i < len ; ++i)
        {
            num[i] = str[len - i - 1] - '0';
        }
    }
    int len;
    int num[30];
};

Big multi(Big a, int b)
{
    Big res;
    int up = 0, i;
    for(i = 0; i < a.len; ++i)
    {
        up = up + a.num[i] * b;
        res.num[i] = up % 10;
        up = up / 10;
    }
    while(up != 0)
    {
        res.num[i++] = up % 10;
        up /= 10;
    }
    res.len = i;
    return res;
}

bool isSameNums(Big a, Big b)
{
    if(a.len != b.len)
        return false;
    int dic[10] = {0};
    for(int i = 0; i < a.len; ++i)
    {
        ++dic[a.num[i]];
        --dic[b.num[i]];
    }
    for(int i = 0; i < a.len; ++i)
    {
        if(dic[i] != 0)
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
    string str;
    cin >> str;
    Big big1(str);
    Big big2 = multi(big1, 2);
    if(isSameNums(big1, big2))
        printf("Yes\n");
    else
        printf("No\n");
    printBig(big2);

    return 0;
}




/*
20:44
21:36
*/

/*
# test case1:
1234567899

# result1:
Yes
2469135798
*/