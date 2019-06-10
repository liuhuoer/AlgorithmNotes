#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int n;

string change(string str, int& e)
{
    int i = 0;
    while(str.size() > 0 && str[0] == '0')
        str.erase(str.begin());
    if(str[0] == '.')
    {
        str.erase(str.begin());
        while(str.size() > 0 && str[0] == '0')
        {
            str.erase(str.begin());
            --e;
        }
    }
    else{
        while(i < str.size() && str[i] != '.')
        {
            ++i;
            ++e;
        }
        if(i < str.size())
            str.erase(str.begin() + i);
    }
    string res;
    //if(str[i - 1] == '.')
    if(str.size() == 0)
        e = 0;

    for(int j = 0; j < n; ++j)
    {
        if(j < str.size())
            res += str[j];
        else
            res += '0';
    }
    return res;
}

int main()
{
    int e1 = 0, e2 = 0;
    string str1, str2, n1, n2;
    cin >> n >> str1 >> str2;
    n1 = change(str1, e1);
    n2 = change(str2, e2);
    if(e1 == e2 && n1 == n2)
    {
        cout << "YES 0." << n1 << "x10^" << e1;
    }
    else{
        cout << "NO 0." << n1 << "x10^" << e1 << " 0." << n2 << "x10^" << e2;
    }

    return 0;
}




/*
19:43
20:20
*/

/*
# test case1:
3 12300 12358.9

# result1:
YES 0.123x10^5

# test case2:
3 120 128

# result2:
NO 0.120x10^3 0.128x10^3

# test case3:
4 0000 0000.00

# result3:
YES 0.0000*10^0

# test case4:
3 0.0520 0.0521

# test case4:
3 0.000 0

# result4:
YES 0.000x10^0
*/