# include <cstdio>
# include <cstring>
# include <string>
# include <iostream>
using namespace std;

struct Big
{
    Big(){
        memset(num, 0, sizeof(num));
        len = 0;
    }
    Big(const string& str)
    {
        len = str.size();
        for(int i = 0; i < len; ++i)
            num[i] = str[len - 1 - i] - '0';
    }
    int num[1010];
    int len;
};


Big divide(Big a, int b, int& r)
{
    Big c;
    c.len = a.len;
    for(int i = a.len - 1; i >= 0; --i)
    {
        r = r * 10 + a.num[i];
        if(r < b)
            c.num[i] = 0;
        else{
            c.num[i] = r / b;
            r = r % b;
        }
    }
    while(c.len - 1 >= 0 && c.num[c.len - 1] == 0)
        --c.len;
    return c;
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
    int b, r = 0;
    cin >> str1 >> b;
    Big big1(str1);
    printBig(divide(big1, b, r));
    printf(" %d", r);

    return 0;
}




/*
19:05
20:00
*/

/*
# test case1:
123456789050987654321 7

# result1:
17636684150141093474 3
*/