#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 1010;

struct Window
{
    int endTime, popTime;
    queue<int> q;
} wd[21];

int converTime(int m, int s)
{
    return m * 60 + s;
}

int main()
{
    int w, wNum, n, q;
    int stTime = converTime(8, 0);
    int edTime = converTime(17, 0);
 
    scanf("%d%d%d%d", &w, &wNum, &n, &q);
    int serTime[MAXN];
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &serTime[i]);
    }
    //init
    for(int i = 0 ; i < w; ++i)
    {
        wd[i].endTime = stTime;
        wd[i].popTime = stTime;
    }

    int index = 0;
    int ans[MAXN];
    for(int i = 0; i < min(n, w * wNum); ++i)
    {
        wd[index % w].endTime += serTime[index];
        if(index < w)
            wd[index].popTime = serTime[index];
        wd[index % w].q.push(index);
        ans[index] = wd[index % w].endTime;
        ++index;
    }
    for(; index < n; ++index)
    {
        int idx = -1, minPopTime = 1 << 30;
        for(int i = 0; i < w; ++i)
        {
            if(wd[i].popTime < minPopTime)
            {
                minPopTime = wd[i].popTime;
                idx = i;
            }
        }

        Window & wt = wd[idx];
        wt.q.pop();
        wt.q.push(serTime[index]);
        wt.popTime += serTime[wt.q.front()];
        wt.endTime += serTime[index];
        ans[index] = wt.endTime;
    }
    for(int i = 0, tmp; i < q; ++i)
    {
        scanf("%d", &tmp);
        tmp = tmp - 1;
        if(ans[tmp] - serTime[tmp] >= edTime)
            printf("Sorry\n");
        else
        {
            printf("%02d:%02d\n", ans[tmp] / 60, ans[tmp] % 60);
        }
    }

    return 0;
}


/*
Sample Input:
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7
Sample Output:
08:07
08:06
08:10
17:00
Sorry
*/


/*
10:43
*/