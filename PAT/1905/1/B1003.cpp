#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n; 
    scanf("%d", &n);
    char str[105];
    for(int i = 0; i < n; ++i)
    {
        bool flag = true;
        scanf("%s", str);
        int len = strlen(str);
        int pos_P, pos_T, num_P = 0, num_T = 0;
        for(int j = 0; j < len; ++j)
        {
            if(str[j] == 'P')
            {
                pos_P = j;
                ++num_P;
            }
            else if(str[j] == 'T')
            {
                pos_T = j;
                ++num_T;
            }     
            else if(str[j] != 'A')
                flag = false;
        }
        if(num_P != 1 || num_T != 1 || pos_T - pos_P <= 1 || flag == false)
        {
            printf("No\n");
            continue;
        }

        int x = pos_P, y = pos_T - pos_P - 1, z = len - 1 - pos_T;
        if( (z - x * (y - 1)) != x)
            printf("No\n");
        else
            printf("Yes\n");
    }

    return 0;
}




/*
21:23
22:26
*/

/*
# test case1:
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA

# result1:
YES
YES
YES
YES
NO
NO
NO
NO
*/