#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int exceed[105];

struct Student
{
    Student()
    {
        id = -1;
        ge = 0, gi = 0;
        memset(choices, -1, sizeof(choices));
        rank = -1;
    }
    int id;
    int ge, gi;
    int choices[6];
    int rank;
};
struct School
{
    School()
    {
        num_stu = 0;
        memset(stu_admit, -1, sizeof(stu_admit));
    }
    int num_stu;
    int stu_admit[405];
};

bool cmp(Student a, Student b)
{
    if((a.ge + a.gi) != (b.ge + b.gi))
        return (a.ge + a.gi)/ 2 > (b.ge + b.gi) / 2;
    else if(a.ge != b.ge)
        return a.ge > b.ge;
}

bool cmp_id(int a, int b)
{
    return a < b;
}

int main()
{
    School sch[105];
    Student stu[405];
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < M; ++i)
    {
        scanf("%d", &exceed[i]);
    }
    for(int i = 0; i < N; ++i)
    {
        scanf("%d %d", &stu[i].ge, &stu[i].gi);
        stu[i].id = i;
        for(int j = 0; j < K; ++j)
        {
            scanf("%d", &stu[i].choices[j]);
        }
    }
    sort(stu, stu + N, cmp);

    //sort
    stu[0].rank = 1;
    for(int i = 0; i < N; ++i)
    {
        if(i > 0 && stu[i].ge == stu[i - 1].ge && stu[i].gi == stu[i - 1].gi)
            stu[i].rank = stu[i - 1].rank;
        else if(i > 0)
            stu[i].rank = i + 1;
        
        for(int j = 0; j < K; ++j)
        {
            int choice = stu[i].choices[j];
            if(sch[choice].num_stu == exceed[choice])
            {
                //admit
                if(stu[i].rank == stu[i - 1].rank && sch[choice].stu_admit[sch[choice].num_stu - 1] == stu[i - 1].id)
                {
                    sch[choice].stu_admit[sch[choice].num_stu] = stu[i].id;
                    if(stu[i].id == 9)
                        printf("9\n");
                    ++sch[choice].num_stu;
                    break;
                }
            }
            else if(sch[choice].num_stu < exceed[choice]){
                //admit
                sch[choice].stu_admit[sch[choice].num_stu] = stu[i].id;
                ++sch[choice].num_stu;
                break;
            }
        }
    }
    for(int i = 0; i < M; ++i)
    {
        sort(sch[i].stu_admit, sch[i].stu_admit + sch[i].num_stu);
        for(int j = 0; j < sch[i].num_stu; ++j)
        {
            printf("%d", sch[i].stu_admit[j]);
            if(j != sch[i].num_stu)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}


/*
# test case1:
11 6 3
2 1 2 2 2 3
100 100 0 1 2
60 60 2 3 5
100 90 0 3 4
90 100 1 2 0
90 90 5 1 3
80 90 1 0 2
80 80 0 1 2
80 80 0 1 2
80 70 1 3 2
70 80 1 2 3
100 100 0 2 4
*/