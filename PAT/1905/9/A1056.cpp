#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 1010;

struct Mouse
{
    int weight, rank;
};

int main()
{
    int np, ng;
    Mouse mou[MAXN];
    scanf("%d %d", &np, &ng);
    for(int i = 0; i < np; ++i)
        scanf("%d", &mou[i].weight);
    
    int value;
    queue<int> q;
    for(int i = 0; i < np; ++i)
    {
        scanf("%d", &value);
        q.push(value);
    }
    int tmp = np, group;
    while(q.size() != 1)
    {
        if(tmp % ng == 0)
            group = tmp / ng;
        else
            group = tmp / ng + 1;

        for(int i = 0; i < group; ++i)
        {
            int k = q.front();
            for(int j = 0; j < ng; ++j)
            {
                if(i * ng + j >= tmp)
                    break;
                int front = q.front();
                if(mou[front].weight > mou[k].weight)
                    k = front;
                mou[front].rank = group + 1;
                q.pop();
            }
            q.push(k);
        }
        tmp = group;
    }
    mou[q.front()].rank = 1;

    for(int i = 0; i < np; ++i)
    {
        printf("%d", mou[i].rank);
        if(i != np - 1)
            printf(" ");
    }

    return 0;
}




/*
19:25
20:58
*/

/*
# test case1:
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3

# test result1:
5 5 5 2 5 5 5 3 1 3 5

*/