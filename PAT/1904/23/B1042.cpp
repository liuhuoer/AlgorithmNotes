#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int dic[30];

int main()
{
    memset(dic, 0, sizeof(dic));
    string str;
    getline(cin, str);
    int len_str = str.size();
    for(int i = 0; i < len_str; ++i)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            ++dic[str[i] - 'A'];
        }
        else if(str[i] >= 'a' && str[i] <= 'z')
        {
            ++dic[str[i] - 'a'];
        }
    }
    int max = 0;
    for(int i = 0; i < 26; ++i)
    {
        if(dic[max] < dic[i])
            max = i;
    }
    printf("%c %d", max + 'a', dic[max]);

    return 0;
}


/*
16:29
16:47
*/

/*
# test case1:
This is a simple TEST.  there ARE numbers and other symbols 1&2&3...
*/