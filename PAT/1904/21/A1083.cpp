#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Student
{
    Student()
    {
        pass = false;
    }
    char name[15];
    char id[15];
    int grade;
    bool pass;
};

bool cmp(Student a, Student b)
{
    return a.grade > b.grade;
}

int main()
{
    Student stu[50];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%s %s %d", &stu[i].name, &stu[i].id, &stu[i].grade);
    }
    int left, right;
    scanf("%d %d", &left, &right);
    sort(stu, stu + n, cmp);
    int pass_num = 0;
    for(int i = 0; i < n; ++i)
    {
        if(left <= stu[i].grade && stu[i].grade <= right)
        {
            ++pass_num;
            stu[i].pass = true;
        }
    }
    if(pass_num == 0)
        printf("None\n");
    else
    {
        for(int i = 0; i < n; ++i)
        {
            if(stu[i].pass)
                printf("%s %s\n", stu[i].name, stu[i].id);
        }
    }
    return 0;
}




/*
# test case1:
4
Tom CS1 59
Joe Math1 89
Mike CS3 100
Mary EE3 95
60 100

#test case2:
2
Jean AA2 60
Ann CS1 80
90 95
*/