#include <cstdio> 
#include <string>
#include <map>
#include <iostream>
using namespace std;

const int N = 13;

string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok","mer", "jou"};

string numToStr[170];
map<string, int> strToNum;

void init()
{
    for(int i = 0; i < 13; ++i)
    {
        numToStr[i] = unitDigit[i];
        strToNum[unitDigit[i]] = i;
        numToStr[i * 13] = tenDigit[i];
        strToNum[tenDigit[i]] = i * 13;
    }
    for(int i = 1; i < 13; ++i)
    {
        for(int j = 1; j < 13; ++j)
        {
            string str = tenDigit[i] + " " + unitDigit[j];
            numToStr[i * 13 + j] = str;
            strToNum[str] = i * 13 + j;
        }
    }
}

// version2:
int main()
{
    init();
    int n;
    scanf("%d%*c", &n);
    for(int i = 0; i < n; ++i)
    {
        string str;
        getline(cin, str);
        if(str[0] >= '0' && str[0] <= '9')
        {
            int num = 0;
            for(int j = 0; j < str.size(); ++j)
            {
                num = num * 10 + str[j] - '0';
            }
            cout << numToStr[num] << endl;
        }
        else{
            cout << strToNum[str] << endl;
        }
    }

    return 0;
}

// version1:
/*
string toMars(string str)
{
    //toInt
    int num = 0;
    for(int i = 0; i < str.size(); ++i)
    {
        num = num * 10 + str[i] - '0';
    }
    //toMar
    int tmp[200];
    string res;
    int count = 0;
    do{
        tmp[count++] = num % 13;
        num /= 13;
    }while(num);
    for(int i = count - 1; i >= 0; --i)
    {
        if(i != 0)
            res += tenDigit[tmp[i]];
        else
            res += unitDigit[tmp[i]];

        if(i > 0)
            res += " ";
    }

    return res;
}

string toEarth(string str)
{
    int res[200], count = 0;
    //to int[]
    for(int i = 0; i < str.size(); ++i)
    {
        string num;
        while(str[i] != ' ' && i < str.size())
        {
            num += str[i];
            ++i;
        }
        if(str[i] == ' ' || i == str.size())
            ++count;
        //map this string to interager
        for(int j = 0; j < N; ++j)
        {
            if(unitDigit[j] == num)
            {
                res[count - 1] = j;
                break;
            }
            else if(tenDigit[j] == num)
            {
                if(i == str.size())
                    res[count - 1] = j * 13;
                else
                    res[count  - 1] = j;
                break;
            }
        }
    }
    //toInt
    int resAll = 0;
    for(int i = 0; i < count; ++i)
    {
        resAll = resAll * N + res[i];
    }
    //toString
    string resStr;
    do{
        resStr += resAll % 10 + '0';
        resAll /= 10;
    }while(resAll);
    //reverse resStr
    int size = resStr.size();
    for(int i = 0; i < size / 2; ++i)
    {
        char t = resStr[i];
        resStr[i] = resStr[size - 1 - i];
        resStr[size - 1 - i] = t;
    }

    return resStr;
}

int main()
{
    int n;
    scanf("%d%*c", &n);
    string res;
    for(int i = 0; i < n; ++i)
    {
        string num;
        getline(cin, num);
        //cout << "test" << i << ":" << num[0] << endl;
        if(num[0] >= '0' && num[0] <= '9')
            res = toMars(num);
        else
            res = toEarth(num);
        cout << res << endl;
    }

    return 0;
}
*/




/*
9:10
11:40
*/

/*
# test case1:
4
29
5
elo nov
tam

# result1:
hel mar
may
115
13
*/