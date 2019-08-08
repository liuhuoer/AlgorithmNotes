#include <cstdio>
#include <algorithm>

using namespace std;

const double INF = 10000000000;

struct Station
{
    Station()
    {
        price = 25;
        distance = 30005;
    }
    double price;
    double distance;
};

bool cmp(Station a, Station b)
{
    return a.distance < b.distance;
}

int main()
{
    Station sta[505];
    double Cmax, D, Davg;               //容量，总距离，距离/每单位油
    int N;                              //油站数
    scanf("%lf %lf %lf %d", &Cmax, &D, &Davg, &N);
    for(int i = 0; i < N; ++i)
    {
        scanf("%lf %lf", &sta[i].price, &sta[i].distance);
    }
    sta[N].price = 0;
    sta[N].distance = D;
    sort(sta, sta + N, cmp);

    if(sta[0].distance != 0)
    {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    else{
        int now = 0;
        double cost = 0.0, tank_now = 0.0, MAX = Cmax * Davg;              //总花费, 邮箱剩余油量, 邮箱加满可走距离


        while(now < N)
        {
            int station_min = -1;
            double price_min = INF;
            for(int i = now + 1; i <= N && sta[i].distance - sta[now].distance <= MAX; ++i)
            {
                if(sta[i].price < price_min)
                {
                    station_min = i;
                    price_min = sta[i].price;
                    if(sta[i].price < sta[now].price)
                    {
                        break;
                    }
                }
            }
            if(station_min == -1)
            {
                printf("The maximum travel distance = %.2lf\n", sta[now].distance + MAX);
                return 0;
            }
            
            double tank_need = (sta[station_min].distance - sta[now].distance) / Davg;
            if(price_min < sta[now].price)
            {
                //oil is enough to station_min
                if(tank_need <= tank_now)
                {
                    tank_now -= tank_need;
                }
                else{
                    cost += (tank_need - tank_now) * sta[now].price;
                    tank_now = 0;
                }
            }
            else{
                //oil is full
                cost += (Cmax - tank_now) * sta[now].price;
                tank_now = Cmax - tank_need;
            }
            now = station_min;
        }
        printf("%.2f\n", cost);
    }


    return 0;
}

/*
        if(now == N)
        {
            printf("%.2f\n", cost);
        }else{
            printf("The maximum travel distance = %.2f\n", sta[now].distance + MAX);
        }
*/


/*
14:57
19:27
*/

/*
# test case1:
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300

# test case2:
50 1300 12 2
7.10 0
7.00 600
*/