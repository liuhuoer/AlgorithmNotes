#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int scores[6];
int N, K; 

struct Student
{
public:
    Student()
    {
        id = -1; 
        memset(grade, -1, sizeof(grade));
        grade_sum = 0;
        full_grade_num = 0;
        pass = false;
    }

    int id;
    int grade[6];
    int grade_sum;
    int full_grade_num;
    bool pass;
};
//}stu[105];

/*
void init()
{
    for(int i = 0; i < N; ++i)
    {
        stu[i].pass = false;
        stu[i].grade_sum = 0;
        stu[i].full_grade_num = 0;
        //memset(stu[i].grade, -1, sizef(stu[i].grade));
        memset(stu[i].grade, -1, sizeof(stu[i].grade));
    }
}
*/

bool cmp(Student a, Student b)
{
    if(a.grade_sum != b.grade_sum)
        return a.grade_sum > b.grade_sum;
    if(a.full_grade_num != b.full_grade_num)
        return a.full_grade_num > b.full_grade_num;
    if(a.id != b.id)
        return a.id < b.id;

}

int main()
{
    Student stu[105];
    int M;
    //input
    scanf("%d %d %d", &N, &K, &M);
    //init();
    for(int i = 0; i < K; ++i)
    {
        scanf("%d", &scores[i]);
    }
    int stu_sum = 0;
    for(int i = 0; i < M; ++i)
    {
        int id, num, grade;
        scanf("%d %d %d", &id, &num, &grade);
        --num; //begin from 0
        int j;
        for(j = 0; j < stu_sum; ++j)
        {
            //old Student's new score
            if(id == stu[j].id)
            {
                if(grade > 0)
                   stu[j].pass = true;
                if(grade > stu[j].grade[num])
                    stu[j].grade[num] = grade;
                //else if(stu[j].grade[num] == 0 && (grade == 0 || grade == -1))
                else if(stu[j].grade[num] == -1 && (grade == 0 || grade == -1))
                    stu[j].grade[num] = 0;
                break;
            }
        }
        //new Student
        if(j == stu_sum)
        {
            ++stu_sum;
            stu[j].id = id;
            if(grade > 0)
                stu[j].pass = true;
            if(grade > stu[j].grade[num])
                stu[j].grade[num] = grade;
            else if(stu[j].grade[num] == -1 && (grade == 0 || grade == -1))
                stu[j].grade[num] = 0;
        }
    }
    //caculate grade_sum and full_grade_num
    for(int i = 0; i < stu_sum; ++i)
    {   
        for(int j = 0; j < K; ++j)
        {
            if(stu[i].grade[j] == scores[j])
                ++stu[i].full_grade_num;
            if(stu[i].grade[j] == -1)
                continue;
            else
                stu[i].grade_sum += stu[i].grade[j];
        }
    }
    // sort and caculate rank
    sort(stu, stu + stu_sum, cmp);
    int rank = 1;
    for(int i = 0; i < stu_sum; ++i)
    {
        if(i > 0 && stu[i].grade_sum != stu[i - 1].grade_sum)
            rank = i + 1;
        //output
        if(stu[i].pass)
        {
            printf("%d %05d %d ", rank, stu[i].id, stu[i].grade_sum);

            /*
            * for(int j = 0; j < K; ++j)
            * {
            *     if(stu[i].grade[j] >= 0)
            *         printf("%d", stu[i].grade[j]);
            *     else if(stu[i].grade[j] == -1)
            *         printf("-");
            *   
            *     if(j != K - 1)
            *         printf(" ");
            *     else
            *         printf("\n");
            * }
            */

            for(int j = 0; j < K; ++j)
            {
                if(stu[i].grade[j] == -1)
                    printf(" -");        
                else
                    printf(" %d", stu[i].grade[j]);
            }
            printf("\n");
        }

    }

    return 0;
}



/*
# test case1:
7 4 20
20 25 25 30
2 2 12
7 4 17
5 1 19
7 2 25
5 1 20
2 2 2
5 1 15
1 1 18
4 3 25
2 2 25
5 3 22
6 4 -1
1 2 18
2 1 20
4 1 15
2 4 18
1 3 4
1 4 2
5 2 -1
4 2 0
*/