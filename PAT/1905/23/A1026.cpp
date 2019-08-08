#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 10010;
const int MAXW = 105;
const int INF = 1000000000;

struct Person
{
    int arriveTime, startTime, serTime;
    bool isVip;
};

struct Table
{
    int endTime;
    bool isVip;
    int serNum;
} tb[MAXW];

vector<Person> ps;

bool cmpArTime(Person a, Person b)
{
    return a.arriveTime < b.arriveTime;
}

bool cmpStTime(Person a, Person b)
{
    return a.startTime < b.startTime;
}

int findNextVip(int index)
{
    for(++index; ps[index].isVip == 0 && index < ps.size(); ++index)
        ;
    return index;
}

int converTime(int h, int m, int s)
{
    return h * 3600 + m * 60 + s;
}

void allocate(int index, int idx)
{
    if(ps[index].arriveTime <= tb[idx].endTime)
        ps[index].startTime = tb[idx].endTime;
    else
        ps[index].startTime = ps[index].arriveTime;
    
    tb[idx].endTime = ps[index].startTime + ps[index].serTime;
    tb[idx].serNum++;
}

int main()
{
    int n;
    scanf("%d", &n);
    int stTime = converTime(8, 0, 0);
    int edTime = converTime(21, 0, 0);
    Person tmpPs;
    for(int i = 0, h, m, s, serTime, isVip; i < n; ++i)
    {
        scanf("%d:%d:%d %d %d", &h, &m, &s, &serTime, &isVip);
        tmpPs.arriveTime = converTime(h, m, s);
        if(tmpPs.arriveTime >= edTime)
            continue;
        tmpPs.startTime = edTime;
        tmpPs.serTime = serTime >= 120 ? 7200 : serTime * 60;
        tmpPs.isVip = isVip;
        ps.push_back(tmpPs);
    }
    int w, wVip, wVipNo[MAXW];
    scanf("%d%d", &w, &wVip);
    for(int i = 0; i < w; ++i)
    {
        tb[i].endTime = stTime;
        tb[i].isVip = 0;
        tb[i].serNum = 0;
    }
    for(int i = 0, tmpWNo  = 0; i < wVip; ++i)
    {
        scanf("%d", &tmpWNo);
        tb[tmpWNo - 1].isVip = 1;
    }
    sort(ps.begin(), ps.end(), cmpArTime);
    int index = 0, indexVip = findNextVip(-1);
    while(index < ps.size())
    {
        int idx = -1, minEndTime = INF;
        for(int i = 0; i < w; ++i)
        {
            if(tb[i].endTime < minEndTime)
            {
                minEndTime = tb[i].endTime;
                idx = i;
            }
        }
        if(tb[idx].endTime >= edTime)
            break;
        if(ps[index].isVip == 1 && index < indexVip)
        {
            ++index;
            continue;
        }
        
        if(tb[idx].isVip == 1)
        {
            if(ps[index].isVip == 1)
            {
                allocate(index, idx);
                if(index == indexVip)
                    indexVip = findNextVip(index);
                ++index;
            }else{
                if(indexVip < ps.size() && ps[indexVip].arriveTime <= tb[idx].endTime)
                {
                    allocate(indexVip, idx);
                    indexVip = findNextVip(indexVip);
                }else{
                    allocate(index, idx);
                    ++index;
                }
            }
        }else{
            if(ps[index].isVip == 0)
            {
                allocate(index, idx);
                ++index;
            }else{
                int idxVipFirst = -1, minVipTb = INF;
                for(int k = 0; k < w; ++k)
                {
                    if(tb[k].isVip == 1 && tb[k].endTime < minVipTb)
                    {
                        minVipTb = tb[k].endTime;
                        idxVipFirst = k;
                    }
                }
                if(idxVipFirst != -1 && tb[idxVipFirst].endTime <= ps[index].arriveTime)
                {
                    allocate(index, idxVipFirst);
                    if(index == indexVip)
                        indexVip = findNextVip(index);
                    ++index;
                }else{
                    allocate(index, idx);
                    if(index == indexVip)
                        indexVip = findNextVip(index);
                    ++index;
                }
            }
        }
    }
    sort(ps.begin(), ps.end(), cmpStTime);
    for(int i = 0; i < ps.size() && ps[i].startTime < edTime; ++i)
    {
        int t1 = ps[i].arriveTime, t2 = ps[i].startTime;
        printf("%02d:%02d:%02d", t1 / 3600, (t1 % 3600) / 60, t1 % 60);
        printf(" %02d:%02d:%02d", t2 / 3600, (t2 % 3600) / 60, t2 % 60);
        printf(" %.0f\n", round((t2 - t1) / 60.0));
    }
    for(int i = 0; i < w; ++i)
    {
        printf("%d", tb[i].serNum);
        if(i < w - 1)
            printf(" ");
    }

    return 0;
}

/*
Sample Input:
9
20:52:00 10 0
08:00:00 20 0
08:02:00 30 0
20:51:00 10 0
08:10:00 5 0
08:12:00 10 1
20:50:00 10 0
08:01:30 15 1
20:53:00 10 1
3 1
2
Sample Output:
08:00:00 08:00:00 0
08:01:30 08:01:30 0
08:02:00 08:02:00 0
08:12:00 08:16:30 5
08:10:00 08:20:00 10
20:50:00 20:50:00 0
20:51:00 20:51:00 0
20:52:00 20:52:00 0
3 3 2
*/


/*
10:21
13:21
*/