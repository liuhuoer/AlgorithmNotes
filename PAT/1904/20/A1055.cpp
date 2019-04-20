#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Richest
{
    char name[8];
    int age;
    long worth;
};

struct Query
{
    int num;
    int left;
    int right;
    Richest res[105];
};

bool cmp(Richest a, Richest b)
{
    if(a.worth != b.worth)
        return a.worth > b.worth;
    else if(a.age != b.age)
        return a.age < b.age;
    else
    {
        return strcmp(a.name, b.name) < 0;
    }
}

int main()
{
    Richest rich[1010];
    Query query[105];
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i)
    {
        scanf("%s %d %ld", &rich[i].name, &rich[i].age, &rich[i].worth);
    }
    for(int i = 0; i < m; ++i)
    {
        scanf("%d %d %d", &query[i].num, &query[i].left, &query[i].right);
        int num_res = 0;
        for(int j = 0; j < n; ++j)
        {
            if(query[i].left <= rich[j].age && rich[j].age <= query[i].right)
            {
                query[i].res[num_res++] = rich[j];
            }
        }
        printf("Case #%d:\n", i + 1);
        sort(query[i].res, query[i].res + num_res, cmp);
        for(int k = 0; k < query[i].num; ++k)
        {
            if(num_res == 0)
                printf("None\n");
            else if(k + 1 <= num_res)
                printf("%s %d %ld\n", query[i].res[k].name, query[i].res[k].age, query[i].res[k].worth);
        }
    }

    return 0;
}


/* 
#test case 1:
12 4
Zoe 35 2333
Bob 24 5888
Ann 95 999999
Will 30 -22
Cin 76 76000
Ali 18 88888
Joe 32 3222
Mic 5 300000
Ross 40 5888
Dob 24 5888
Bil 24 5888
Nobb 5 0
4 15 45
4 30 35
4 5 95
1 45 50
*/