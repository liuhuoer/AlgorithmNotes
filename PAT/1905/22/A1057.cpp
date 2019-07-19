#include <stack>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 100001;
const int sqrN = 316;

stack<int> st;
int block[sqrN + 1];
int table[MAXN];

void push(int k)
{
    st.push(k);
    ++block[k / sqrN];
    ++table[k];
}

void pop()
{
    int res = st.top();
    st.pop();
    --block[res / sqrN];
    --table[res];
    printf("%d\n", res);
}

void peekMedian(int k)
{
    int sum = 0;
    int index = 0;
    while(sum + block[index] < k)
        sum += block[index++];
    int num = index * sqrN;
    while(sum + table[num] < k)
        sum += table[num++];
    printf("%d\n", num);
}

int main()
{
    int N;
    memset(block, 0, sizeof(block));
    memset(table, 0, sizeof(table));
    scanf("%d", &N);
    char cmd[20];
    for(int i = 0, tmp; i < N; ++i)
    {
        scanf("%s", &cmd);
        if(strcmp(cmd, "Push") == 0)
        {
            scanf("%d", &tmp);
            push(tmp);
        }else if(strcmp(cmd, "Pop") == 0){
            if(st.empty())
                printf("Invalid\n");
            else
                pop();
        }else{
            if(st.empty())
                printf("Invalid\n");
            else
            {
                int k = st.size();
                if(k % 2 == 1)
                    k = (k + 1) / 2;
                else 
                    k = k / 2;
                peekMedian(k);
            }
        }
    }

    return 0;
}




/*
15:50
17:08
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
