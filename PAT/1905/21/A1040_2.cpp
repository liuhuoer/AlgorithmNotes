#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const ll P = 10000019;
const ll MAXN = 1010;

ll powP[MAXN], H1[MAXN], H2[MAXN];

void init()
{
    powP[0] = 1;
    for(int i = 1; i < MAXN; ++i)
    {
        powP[i] = (powP[i - 1] * P) % MOD;
    }
}

void calH(ll H[], string & str)
{
    H[0] =  str[0];
    for(int i = 1; i < str.length(); ++i)
    {
        H[i] = (H[i - 1] * P + str[i]) % MOD;
    }
}

int calSingleSubH(ll H[], int i, int j)
{
    if(i == 0)
        return H[j];
    else
        return ((H[j] - H[i - 1] * powP[j - i + 1]) % MOD + MOD) % MOD;
}

int binarySearch(int l, int r, int len, int i, int isEven)
{
    while(l < r)
    {
        int mid = (l + r) / 2;
        int H1L = i - mid + isEven;
        int H1R = i;
        int H2L = len - 1 - (i + mid);
        int H2R = len - 1 - (i + isEven);
        int hash1 = calSingleSubH(H1, H1L, H1R);
        int hash2 = calSingleSubH(H2, H2L, H2R);
        if(hash1 != hash2)
            r = mid;
        else
            l = mid + 1;
    }
    return l - 1;
}


int main()
{
    init();
    string str, str_rev;
    getline(cin, str);
    calH(H1, str);
    reverse(str.begin(), str.end());
    calH(H2, str);
    int ans = 0;
    //odd
    for(int i = 0; i < str.length(); ++i)
    {
        int max_len = min(i, (int)str.length() - 1 - i) + 1;
        int k = binarySearch(0, max_len, str.length(), i, 0);
        ans = max(ans, k * 2 + 1);
    }
    //even
    for(int i = 0; i < str.length(); ++i)
    {
        int max_len = min(i, (int)str.length() - 1 - i) + 1;
        int k = binarySearch(0, max_len, str.length(), i, 1);
        ans = max(ans, k * 2);
    }
    printf("%d\n", ans);
 

    return 0;
}


/*
Sample Input:
Is PAT&TAP symmetric?
Sample Output:
11
*/

