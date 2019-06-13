#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Student
{
    //char name[15];
    string name;
    //char id[15];
    string id;
    int grade;
};

bool cmp(Student a, Student b)
{
    return a.grade > b.grade;
}

int main()
{
    //Student stu[50];
    vector<Student> stu;
    Student tmp;
    int n;
    cin >> n;
    //scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        cin >> tmp.name >> tmp.id >> tmp.grade;
        stu.push_back(tmp);
    }
    int left, right;
    cin >> left >> right;
    //scanf("%d %d", &left, &right);
    sort(stu.begin(), stu.end(), cmp);
    int pass_num = 0;
    for(int i = 0; i < n; ++i)
    {
        if(left <= stu[i].grade && stu[i].grade <= right)
        {
            cout << stu[i].name << " " << stu[i].id << endl;
            //printf("%s %s\n", stu[i].name, stu[i].id);
            ++pass_num;
        }
    }
    if(pass_num == 0)
        printf("NONE\n");

    return 0;
}
/*
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct sRecord
{
    string name;
    string id;
    int score;
};
bool cmp(const sRecord& p1, const sRecord& p2)
{
    return p1.score > p2.score;
}
int main()
{
    int n;
    int maxN, minN;
    sRecord temp;
    vector<sRecord> records;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> temp.name;
        cin >> temp.id;
        cin >> temp.score;
        records.push_back(temp);
    }
    cin >> minN;
    cin >> maxN;
    sort(records.begin(), records.end(), cmp);
    auto it = records.begin();
    while (it!=records.end())
    {
        if ((*it).score <= maxN && ((*it).score >= minN))
        {
            cout << (*it).name << " " << (*it).id << endl;
            count++;
        }
        it++;
    }
    if (count == 0)
        cout << "NONE";
}
*/




/*
# test case1:
4
Tom CS000001 59
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
60 100

#test result1:
Mike CS991301
Mary EE990830
Joe Math990112

*/