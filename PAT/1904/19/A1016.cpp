#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int fee_rate[24];


class t_Time
{
public:
    t_Time()
    {
        mon = 0;
        day = 0;
        hor = 0;
        min = 0;
    }

    int mon, day, hor, min;
    char flag[15];

};

int sub_time(t_Time a, t_Time b)
{
    int sum = 0;
    int flag = 0;
    if(a.min >= b.min)
        sum += a.min - b.min;
    else
    {
        flag = -1;
        sum += a.min + 60 - b.min;
    }

    if((a.hor + flag) >= b.hor)
        sum += (a.hor - b.hor + flag) * 60;

    return sum;
}

struct User
{
    char name[25];
    vector<t_Time> records;
    int time_long;
    int fee;
};

bool cmp_time(t_Time a, t_Time b)
{
    if(a.mon != b.mon)
        return a.mon < b.mon;
    else if(a.day != b.day)
        return a.day < b.day;
    else if(a.hor != b.hor)
        return a.hor < b.hor;
    else
        return a.min < b.min;
}

bool cmp_name(User a, User b)
{
    int len_min;
    len_min = strlen(a.name) < strlen(b.name) ? strlen(a.name) : strlen(b.name);
    for(int i = 0; i < len_min; ++i)
        if(a.name[i] != b.name[i])
            return a.name[i] < b.name[i];
    return strlen(a.name) < strlen(b.name);
}

float sum_fee_rate(int left, int right)
{
    float sum = 0.0;
    for(int i = left; i < right; ++i)
    {
        sum += 60 * fee_rate[i];
    }
    return sum;
}

int main()
{
    User user[10];

    //char str_fee_rate[100];
    string str_fee_rate;
    //gets(str_fee_rate);
    getline(cin, str_fee_rate);
    for(int i = 0; i < 24; ++i)
        fee_rate[i] = (str_fee_rate[i * 3] - '0') * 10 + (str_fee_rate[i * 3 + 1] - '0');
    int n;              //the num of records
    scanf("%d", &n);
    int num_user = 0;
    for(int i = 0; i < n; ++i)
    {
        char name[25];
        t_Time t;
        scanf("%s %d:%d:%d:%d %s", &name, &t.mon, &t.day, &t.hor, &t.min, &t.flag);

        int j;
        for(j = 0; j < num_user; ++j)
        {
            if(strcmp(name, user[j].name) == 0)        //user[] have this user
            {
                user[j].records.push_back(t);
                break;
            }
        }
        if(j == num_user)   //no this user
        {
            strcpy(user[num_user].name, name);
            user[num_user].records.push_back(t);
            ++num_user;
        }
    }
    sort(user, user + num_user, cmp_name);
    for(int i = 0; i < num_user; ++i)
    {
        sort(user[i].records.begin(), user[i].records.end(), cmp_time);
    }
    for(int i = 0; i < num_user; ++i)
    {
        int time_long = 0;  //time_long for every user
        float fee = 0.0;
        float total_fee = 0.0;

        printf("%s %02d\n", user[i].name, user[i].records[0].mon);
        for(int j = 0; j < user[i].records.size(); ++j)
        {
            if(strcmp(user[i].records[j].flag, "off-line") == 0)             //*j == off, *(j - 1) == on
            {
                time_long = 0;
                fee = 0.0;

                t_Time& on = user[i].records[j - 1];
                t_Time& off = user[i].records[j];
                if(off.day == on.day)
                {
                    if(off.hor == on.hor)
                    {
                        //time_long += sub_time(off, on);
                        time_long += off.min - on.min;
                        fee += (off.min - on.min) * fee_rate[off.hor];
                    }
                    else
                    {
                        time_long += (off.hor - on.hor - 1) * 60 + (60 - on.min) + off.min;
                        fee += sum_fee_rate(on.hor + 1, off.hor) 
                                                + (60 - on.min) * fee_rate[on.hor]
                                                + off.min * fee_rate[off.hor];

                        // for(int left = 0; left < 24; ++left)         //k == left, k + 1 == right
                        // {
                        //     //t_Time left, right;
                        //     //left.hor = k;
                        //     //right.hor = k + 1;
                            
                        //     if(left == on.hor)
                        //     {
                        //         //time_long += sub_time(on, left);
                        //         time_long += (60 - on.min);
                        //         fee += (60 - on.min) * fee_rate[left];
                        //     }
                        //     if(on.hor < left && left < off.hor)
                        //     {
                        //         time_long += 1 * 60;
                        //         fee += 60 * fee_rate[left];
                        //     }
                        //     if(left == off.hor)
                        //     {
                        //         //time_long += sub_time(on, left);
                        //         time_long += off.min;
                        //         fee += off.min * fee_rate[left];
                        //     }
                           
                        //     /*
                        //     if(left.hor < on.hor && on.hor < right.hor && right.hor < off.hor)
                        //     if((left.hor + 1) == on.hor && on.hor < right.hor && right.hor < off.hor)
                        //     else if(on.hor < left.hor && right.hor < off.hor)
                        //     else if(left.hor < on.hor && off.hor < right.hor)
                        //     else if(on.hor < left.hor && left.hor < off.hor && off.hor < right.hor)
                        //     */
                        //     /*
                        //     if(user[i].records[j - 1].hor < k + 1 && k + 1 < user[i].records[j].hor)            //(k + 1) - subif
                        //     {
                        //         if(k < user[i].records[j - 1].hor)
                        //             time_long += sub_time(right, left);
                        //     }
                        //     else if(user[i].records[j].hor < k + 1)       //off - subif
                        //     {
                        //         if(k < user[i].records[j - 1].hor)
                        //             time_long += sub_time(user[i].records[j], user[i].records[j - 1]);
                        //         if(user[i].records[j - 1].hor < k)
                        //             time_long += sub_time(user[i].records[j], left);
                        //     }
                        //     fee =time_long * fee_rate[k];
                        //     */
                        // }
                    }
                }
                else{
                    time_long += (off.day - on.day - 1) * 24 * 60;
                    time_long += (24 - on.hor - 1) * 60 + (60 - on.min);
                    time_long += off.hor * 60 + off.min;
                    fee += (off.day - on.day - 1) * sum_fee_rate(0, 24);
                    fee += sum_fee_rate(on.hor + 1, 24) + (60 - on.min) * fee_rate[on.hor];
                    fee += sum_fee_rate(0, off.hor) + off.min * fee_rate[off.hor];
                }

                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", user[i].records[j - 1].day,
                                    user[i].records[j - 1].hor,
                                    user[i].records[j - 1].min,
                                    user[i].records[j].day,
                                    user[i].records[j].hor,
                                    user[i].records[j].min,
                                    time_long,
                                    fee /= 100);
                total_fee += fee;
            }
        }
        printf("Total amount: $%.2f\n", total_fee);
    }
    
    return 0;
}



/*
# test case1:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYjj 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYjj 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line

# result1:
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
CYjj 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
 
*/