#include <cstdio>
#include <cstring>

int main()
{
    //input to n, char name[][], char pass[][]
    int n;
    char name[1010][15], pass[1010][15];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%s %s", &name[i], &pass[i]);
    }
    //check every port in pass
    bool flag;              //if change, flag = true
    int len;
    int num_change[1010] = {0};     //the number of changed
    int num = 0;                    //the sum of changed
    for(int i = 0; i < n; ++i)
    {
        flag = false;
        len = strlen(pass[i]);
        //record sum of the changed no. and numbe
        for(int j = 0; j < len; ++j)
        {
            if(pass[i][j] == '1')
            {
                flag = true;
                pass[i][j] = '@';
            }
            else if(pass[i][j] == '0')
            {
                flag = true;
                pass[i][j] = '%';
            }
            else if(pass[i][j] == 'l')
            {
                flag = true;
                pass[i][j] = 'L';
            }
            else if(pass[i][j] == 'O')
            {
                flag = true;
                pass[i][j] = 'o';
            }
            else
                continue;
        }
        if(flag)
            num_change[num++] = i;
    }
     //output
    if(num == 0)
        printf("There is %d account and no account is modified\n", n);
    else
        printf("%d\n", num);
    for(int i = 0; i < num; ++i)
        printf("%s %s\n", name[num_change[i]], pass[num_change[i]]);
    return 0;
}