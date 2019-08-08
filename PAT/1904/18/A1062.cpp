#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct student
{
    char id[10];
    int de, cai, type;      //type->[1, 5]
} stu[100010];

bool cmp(student a, student b)
{
    if(a.type != b.type)
        return a.type < b.type;
    else if((a.de + a.cai) != (b.de + b.cai))
        return (a.de + a.cai) > (b.de + b.cai);
    else if(a.de != b.de)
        return a.de > b.de;
    else
        return strcmp(a.id, b.id) < 0;
}


int main()
{
    int n, L, H;
    scanf("%d %d %d", &n, &L, &H);
    int count = 0;          // the num of stu, who's all grades > 60
    for(int i = 0; i < n; ++i)
    {
        scanf("%s %d %d", &stu[i].id, &stu[i].de, &stu[i].cai);
        if(stu[i].de < L || stu[i].cai < L)
        {
            stu[i].type = 5;
        }
        else
        {
            ++count;
            if(stu[i].de >= H && stu[i].cai >= H)
                stu[i].type = 1;
            else if(stu[i].de >= H && stu[i].cai < H)
                stu[i].type = 2;
            else if(stu[i].de >= stu[i].cai)
                stu[i].type = 3;
            else
                stu[i].type = 4;
        }
    }

    sort(stu, stu + n, cmp);
    printf("%d\n", count);
    for(int i = 0; i < count; ++i)
    {
        printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
    }

    return 0;
}
