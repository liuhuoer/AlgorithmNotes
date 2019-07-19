#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

const int MAXN = 100010;

#define lowbit(i) ((i) & (-i))

stack<int> st;
int C[MAXN], A[MAXN];

void update(int x, int v)
{
    for(int i = x; i <= MAXN; i += lowbit(i))
    {
        C[i] += v;
    }
}

int getSum(int x)
{
    int sum = 0;
    for(int i = x; i > 0; i -= lowbit(i))
    {
        sum += C[i];
    }
    return sum;
}

void peekMedian()
{
    int l = 1, r = MAXN, k = (st.size() + 1) / 2, mid;
    while(l < r)
    {
        mid = (l + r) / 2;
        if(getSum(mid) >= k)
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d\n", l);
}

int main()
{
    int n;
    scanf("%d", &n);

    char cmd[20];
    for(int i = 0, tmp; i < n; ++i)
    {
        scanf("%s", &cmd);
        if(strcmp(cmd, "Push") == 0)
        {
            scanf("%d", &tmp);
            st.push(tmp);
            update(tmp, 1);
        }else if(strcmp(cmd, "Pop") == 0){
            if(st.empty() == true)
                printf("Invalid\n");
            else
            {
                int tmp = st.top();
                printf("%d\n", tmp);
                update(tmp, -1);
                st.pop();
            }
        }else{
            if(st.empty() == true)
                printf("Invalid\n");
            else
                peekMedian();
        }
    }

    return 0;
}




/*
17:15
*/

/*
Sample Input:
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop

Sample Output:
Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid
*/
