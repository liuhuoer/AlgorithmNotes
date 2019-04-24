#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

const char dic[7] = {'P', 'A', 'T', 'e', 's', 't'};
int num_dic[6];

int main()
{
    memset(num_dic, 0, sizeof(num_dic));
    int sum = 0;
    string str;
    getline(cin, str);
    int len_str = str.size();
    for(int i = 0; i < len_str; ++i)
    {
        for(int j = 0; j < 6; ++j)
        {
            if(str[i] == dic[j])
            {
                ++num_dic[j];
                ++sum;
            }
        }
    }
    while(sum)
    {
        for(int i = 0; i < 6; ++i)
        {
            if(num_dic[i] > 0)
            {
                printf("%c", dic[i]);
                --sum;
                --num_dic[i];
            }
        }
    }


    return 0;
}


/*
16:50
17:04
*/

/*
# test case1:
redlesPayBestPATTopTeePHPereatitAPPT
*/