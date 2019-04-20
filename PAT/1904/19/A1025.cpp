#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


struct Student
{
    char id[15];
    int grade;
    int rank_final;
    int rank_local;
    int local_num;
};

bool cmp(Student a, Student b)
{
    if(a.grade != b.grade)
        return a.grade > b.grade;
    else if(strcmp(a.id, b.id) != 0)
        return strcmp(a.id, b.id) < 0;
}

int main()
{
    //Student stu[30010];
    Student stu[30];
    int n;
    scanf("%d", &n);
    int num_stu = 0;
    int m[105] = {0};
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &m[i]);
        for(int j = 0; j < m[i]; ++j)
        {
            scanf("%s %d", &stu[num_stu + j].id,  &stu[num_stu + j].grade);
            stu[num_stu + j].local_num = i + 1;
        }

        sort(stu + num_stu, stu + num_stu + m[i], cmp);
        stu[num_stu].rank_local = 1;
        for(int k = num_stu + 1; k < (num_stu + m[i]); ++k)
        {
            if(stu[k].grade != stu[k - 1].grade)
                stu[k].rank_local = (k + 1) - num_stu;
            else
                stu[k].rank_local = stu[k - 1].rank_local;
        }
        num_stu += m[i];
    }
    sort(stu, stu + num_stu, cmp);
    stu[0].rank_final = 1;
    for(int i = 1; i < num_stu; ++i)
    {
        if(stu[i].grade != stu[i - 1].grade)
            stu[i].rank_final = i + 1;
        else
            stu[i].rank_final = stu[i - 1].rank_final;
    }
    printf("%d\n", num_stu);
    for(int i = 0; i < num_stu; ++i)
    {
        printf("%s %d %d %d\n", stu[i].id, stu[i].rank_final, stu[i].local_num, stu[i].rank_local);
    }
}

/*
# test case1:
2
5
01 95
05 100
03 95
02 77
04 85
4
13 65
11 25
14 100
12 85
*/