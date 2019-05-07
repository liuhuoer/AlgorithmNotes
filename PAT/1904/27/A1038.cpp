#include <cstdio>
//#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(string a, string b)
{
    return a + b < b + a;
}

int main()
{
    int n;
    cin >> n;
    string input[105];
    for(int i = 0; i < n; ++i)
    {
        cin >> input[i];
    }

    sort(input, input + n, cmp);
    string res;
    for(int i = 0; i < n; ++i)
    {
        res += input[i];
    }
    if(res.size() != 0 && res[0] == '0')
        res.erase(res.begin());

    if(res.size() == 0)
        cout << "0" << endl;
    else
        cout << res << endl;

    
    return 0;
}



/*
8:37
8:58
*/


/*
# test case1:
5 32 321 3214 0229 87
*/