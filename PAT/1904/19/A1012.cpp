#include <cstdio>
#include <algorithm>

using namespace std;

int now;        //type_class
const char course[4] = {'A', 'C', 'M', 'E'};
int Rank[10000000][4] = {0};

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

    for(now = 0; now < 4; ++now)
    {
        sort(stu, stu + n, cmp);
        Rank[stu[0].id][now] = 1;
        for(int i = 1; i < n; ++i)
        {
            if(stu[i].grade[now] == stu[i - 1].grade[now])
                Rank[stu[i].id][now] = Rank[stu[i - 1].id][now];
            else
                Rank[stu[i].id][now] = i + 1;
        }
    }

    int query;
    for(int i = 0; i < m; ++i)
    {
        scanf("%d", &query);
        if(Rank[query][0] == 0)
            printf("N/A\n");
        else
        {
            int k = 0;
            for(int j = 1; j < 4; ++j)
            {
                if(Rank[query][j] < Rank[query][k])
                    k = j;
            }
            printf("%d %c\n", Rank[query][k], course[k]);
        }
    }

    return 0;
}

/*
Sample Input:
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
Sample Output:
1 C
1 M
1 E
1 A
3 A
N/A
*/