#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

struct Car
{
    char plate_num[10];
    int records;
    char io[5];
};

bool cmp_id(Car a, Car b)
{
    if(strcmp(a.plate_num, b.plate_num) != 0)
        return strcmp(a.plate_num, b.plate_num) < 0;
    else if(a.records != b.records)
        return a.records < b.records;
}

bool cmp_time(Car a, Car b)
{
    return a.records < b.records;
}

int main()
{
    Car all[10005], valid[10005];
    int query[8005];
    int N, M;
    scanf("%d %d", &N, &M);
    int hor, min, sec;
    for(int i = 0; i < N; ++i)
    {
        scanf("%s %d:%d:%d %s", &all[i].plate_num, &hor, &min, &sec, &all[i].io);
        all[i].records = (hor * 60 + min) * 60 + sec;
    }
    for(int i = 0; i < M; ++i)
    {
        scanf("%d:%d:%d", &hor, &min, &sec);
        query[i] = (hor * 60 + min) * 60 + sec;
    }
    sort(all, all + N, cmp_id);
    int num_valid = 0;
    map<string, int> mcar_time;
    //max paking time
    int max_time = 0;
    for(int i = 0; i < (N - 1); ++i)
    {
        if(strcmp(all[i].io, "in") == 0 && strcmp(all[i + 1].io, "out") == 0 && strcmp(all[i].plate_num, all[i + 1].plate_num) == 0)
        {
            valid[num_valid++] = all[i];
            valid[num_valid++] = all[i + 1];
            mcar_time[all[i].plate_num] += all[i + 1].records - all[i].records;
            if(max_time < mcar_time[all[i].plate_num])
                max_time = mcar_time[all[i].plate_num];
        }
    }
    sort(valid, valid + num_valid, cmp_time);
    //query the num_car
    for(int i = 0; i < M; ++i)
    {
        int num_car = 0;
        int now;
        for(int j = 0; j < num_valid; ++j)
        {
            if(valid[j].records <= query[i])
            {
                if(strcmp(valid[j].io, "in") == 0)
                    ++num_car;
                else if(strcmp(valid[j].io, "out") == 0)
                    --num_car;
            }
        }
        printf("%d\n", num_car);
    }
    for(auto left = mcar_time.begin(); left != mcar_time.end(); ++left)
    {
        if(left->second == max_time)
            printf("%s ", left->first.c_str());
    }
    printf("%02d:%02d:%02d", max_time / 60 / 60, (max_time / 60) % 60, max_time % 60);

    return 0;
}


/*
# test case1:
16 7
JH0 18:00:01 in
ZD0 11:30:08 out
DB8 13:00:00 out
ZA3 23:59:50 out
ZA1 10:23:00 in
ZD0 04:09:59 in
JH0 05:09:59 in
ZA3 11:42:01 out
JH0 05:10:33 in
ZA3 06:30:50 in
JH0 12:23:42 out
ZA3 23:55:00 in
JH0 12:24:23 out
ZA1 17:11:22 out
JH0 18:07:01 out
DB8 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00
*/