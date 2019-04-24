#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int change(char c)
{
    if(c >= '0' && c <= '9')
        return c - '0';
    else if(c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    else if(c >= 'a' && c <= 'z')
        return c - 'a' + 36;
}


int main()
{
    int res[70];
    memset(res, 0, sizeof(res));
    int num, neg = 0;
    string provide, need;
    getline(cin, provide);
    int len_provide = provide.size();
    for(int i = 0; i < len_provide; ++i)
    {
        num = change(provide[i]);
        ++res[num];
    }
    getline(cin, need);
    int len_need = need.size();
    for(int i = 0; i < len_need; ++i)
    {
        num = change(need[i]);
        --res[num];
        if(res[num] < 0)
            ++neg;
    }

    if(neg > 0)
        printf("No %d", neg);
    else
        printf("Yes %d", len_provide - len_need);
    

    return 0;
}



/*
15:52
16:25
*/


/*
# test case1:
ppRYYGrrYBR2258
YrR8RrY

# test case2:
ppRYYGrrYB225
YrR8RrY
*/