#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

bool dic[256];

int main()
{
//    memset(dic, false, sizeof(dic));
    string str, novalue;
    getline(cin, str);
    int len_str = str.size();
    getline(cin, novalue);
    int len_noval = novalue.size();
    for(int i = 0; i < len_noval; ++i)
    {
        dic[novalue[i]] = true;
    }
    for(int i = 0; i < len_str; ++i)
    {
        if(dic[str[i]] == false)
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