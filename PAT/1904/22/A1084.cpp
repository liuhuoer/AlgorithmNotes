#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string all, now;
    //char all[85], now[85];
    getline(cin, all);
    getline(cin, now);
    //gets(all);
    //gets(now);
    int len_all = all.size();
    int len_now = now.size();
    //int len_all = strlen(all);
    //int len_now = strlen(now);

    bool nofirst[125] = {false};
    for(int i = 0; i < len_all; ++i)
    {
        char c1 = all[i], c2;
        if(all[i] >= 'a' && all[i] <= 'z')
            c1 -= 32;
        int j;
        for(j = 0; j < len_now; ++j)
        {
            c2 = now[j];

            if(now[j] >= 'a' && now[j] <= 'z')
                c2 -= 32;
            if(c1 == c2)
                break;
        }
        if(j == len_now && nofirst[c1] == false)
        {
            printf("%c", c1);
            nofirst[c1] = true;
        }
    }

    return 0;
}

/*
# test case1:
7_This_is_a_test
_hs_s_a_es
*/