#include <cstdio>
#include <cstring>

using namespace std;


int main()
{
    int group[1005];
    memset(group, 0, sizeof(group));
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        int g_no, num_stu, grade;
        scanf("%d-%d %d", &g_no, &num_stu, &grade);
        group[g_no] += grade;
    }
    int max = 0;
    for(int i = 1; i < sizeof(group) / sizeof(int); ++i)
    {
        if(group[max] < group[i])
            max = i;
    }
    printf("%d %d\n", max, group[max]);
}

/*
12:04
12:20
*/


/*
# test case1:
6
3-10 99
11-5 87
102-1 0
102-3 100
11-9 89
3-2 61
*/