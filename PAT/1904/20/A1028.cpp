#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Student
{
    char id[6];
    char name[8];
    int grade;
};

bool cmp_1(Student a, Student b)
{
    return strcmp(a.id, b.id) < 0;
}

bool cmp_2(Student a, Student b)
{
    if(strcmp(a.name, b.name) != 0)
        return strcmp(a.name, b.name) < 0;
    else
        return strcmp(a.id, b.id) < 0;
}

bool cmp_3(Student a, Student b)
{
    if(a.grade != b.grade )
        return a.grade < b.grade;
    else
        return strcmp(a.id, b.id) < 0;
}

int main()
{
    Student stu[100005];
    int n, c;
    scanf("%d %d", &n, &c);
    for(int i = 0; i < n; ++i)
    {
        scanf("%s %s %d", &stu[i].id, &stu[i].name, &stu[i].grade);
    }
    if(c == 1)
        sort(stu, stu + n, cmp_1);
    else if(c == 2)
        sort(stu, stu + n, cmp_2);
    else if(c == 3)
        sort(stu, stu + n, cmp_3);
    for(int i = 0; i < n; ++i)
    {
        printf("%s %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
    }
    
    return 0;
}

/*
# test case1:
3 1
07 James 85
10 Amy 90
01 Zoe 60

# test case2:
4 2
07 James 85
10 Amy 90
01 Zoe 60
02 James 98

# test case3:
4 3
07 James 85
10 Amy 90
01 Zoe 60
02 James 90
*/