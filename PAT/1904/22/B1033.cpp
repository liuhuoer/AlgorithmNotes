#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

bool dic[256];

int main()
{
    memset(dic, true, sizeof(dic));
    string novalue, all;
    getline(cin, novalue);
    int size_novalue = novalue.size();
    for(int i = 0; i < size_novalue; ++i)
    {
        if(novalue[i] >= 'A' && novalue[i] <= 'Z')
            novalue[i] = novalue[i] - 'A' + 'a';
        dic[novalue[i]] = false;
    }
    getline(cin, all);
    int size_all = all.size();
    for(int i = 0; i < size_all; ++i)
    {
        //special case
        if(all[i] >= 'A' && all[i] <= 'Z')
        {
            int c = all[i] - 'A' + 'a';
            if(dic[c] == true && dic['+'] == true)
                printf("%c", all[i]);
        }
        else if(dic[all[i]] == true)
            printf("%c", all[i]);
    }

    return 0;
}




/*
14:43 
15:32
*/

/*
# test case1:
7+IE
7_This_is_a_test
*/
