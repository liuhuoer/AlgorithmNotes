#include <cstdio>
#include <algorithm>

using namespace std;

int now;        //type_class
const char course[4] = {'A', 'C', 'M', 'E'};

struct Student
{
    int id;
    int grade[4];
};

bool cmp(Student a, Student b)
{
    return a.grade[now] > b.grade[now];
}

int main()
{
    struct Student stu[2010];
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d %d %d %d", &stu[i].id, 
                 &stu[i].grade[1],
                 &stu[i].grade[2],
                 &stu[i].grade[3]);

        stu[i].grade[0] = (stu[i].grade[1] 
                            + stu[i].grade[2]
                            + stu[i].grade[3]) / 3 + 0.5;
    }
    
    int rank[2010][4] = {0};
    for(now = 0; now < 4; ++now)
    {
        sort(stu, stu + n, cmp);
        rank[stu[0].id][now] = 1;
        for(int i = 1; i < n; ++i)
        {
            if(stu[i].grade[now] == stu[i - 1].grade[now])
                rank[stu[i].id][now] = rank[stu[i - 1].id][now];
            else
                rank[stu[i].id][now] = i + 1;
        }
    }

    int query;
    for(int i = 0; i < m; ++i)
    {
        scanf("%d", &query);
        if(rank[query][0] == 0)
            printf("N/A\n");
        else
        {
            int k = 0;
            for(int j = 1; j < 4; ++j)
            {
                if(rank[query][j] < rank[query][k])
                    k = j;
            }
            printf("%d %c\n", rank[query][k], course[k]);
        }
    }

    return 0;
}