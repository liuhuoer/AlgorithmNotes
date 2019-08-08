#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

struct Person
{
    int comeTime;
    int processTime;
};

int converTime(int h, int m, int s)
{
    return h * 3600 + m * 60 + s;
}

bool cmp(Person a, Person b)
{
    return a.comeTime < b.comeTime;
}

int main()
{
    int n, w;
    scanf("%d%d", &n, &w);
    int stTime = converTime(8, 0, 0);
    int edTime = converTime(17, 0, 0);
    vector<Person> custom;
    int endTime[105];
    fill(endTime, endTime + 105, stTime);
    for(int i = 0, h, m, s, p; i < n; ++i)
    {
        Person ps;
        scanf("%d:%d:%d %d", &h, &m, &s, &p);
        int comeTime = converTime(h, m, s);
        if(comeTime > edTime)
            continue;
        ps.comeTime = comeTime;
        ps.processTime = p > 60 ? 3600 : p * 60;
        custom.push_back(ps);
    }
    sort(custom.begin(), custom.end(), cmp);
    int sumWait = 0;
    for(int i = 0; i < custom.size(); ++i)
    {
        int idx = -1, minEndTime = INF;
        for(int j = 0; j < w; ++j)
        {
            if(endTime[j] < minEndTime)
            {
                minEndTime = endTime[j];
                idx = j;
            }
        }
        //wait or no_wait
        if(endTime[idx] > custom[i].comeTime)
        {
            sumWait += (endTime[idx] - custom[i].comeTime);
            endTime[idx] += custom[i].processTime;
        }else
            endTime[idx] = custom[i].comeTime + custom[i].processTime;
    }
    if(custom.size() == 0)
        printf("0.0");
    else
        printf("%.1f", sumWait / 60.0 / custom.size());

    return 0;
}


/*
Sample Input:
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
Sample Output:
8.2
*/


/*
21:58
10:42
*/