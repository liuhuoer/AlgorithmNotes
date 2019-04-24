#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    bool dic[256];
    memset(dic, true, sizeof(dic));
    string str, novalue;
    getline(cin, str);
    int len_str = str.size();
    getline(cin, novalue);
    int len_noval = str.size();
    for(int i = 0; i < len_noval; ++i)
    {
        dic[novalue[i]] = false;
    }
    for(int i = 0; i < len_str; ++i)
    {
        if(dic[str[i]] == true)
            printf("%c", str[i]);
    }

    return 0;
}


/*
19:01
19:19
*/

/*
# test case1:
They are students.
aeiou
*/