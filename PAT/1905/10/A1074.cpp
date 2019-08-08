#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100010;

struct Node
{
    // init
    Node()
    {
        order = MAXN;
    }
    int address, data, next;
    int order;
} node[MAXN];

bool cmp(Node a, Node b)
{
    return a.order < b.order;
}

int main()
{
    int first, n, k;
    // input
    scanf("%d %d %d", &first, &n, &k);
    int address;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &address);
        scanf("%d %d", &node[address].data, &node[address].next);
        node[address].address = address;
    }

    // traversal
    address = first;
    int count = 0;
    while(address != -1)
    {
        node[address].order = count++;
        address = node[address].next;
    }

    // sort
    sort(node, node + MAXN, cmp);
    n = count;

    // output
    for(int i = 0; i < n / k; ++i)
    {
        for(int j = (i + 1) * k - 1; j > i * k; --j)
        {
            printf("%05d %d %05d\n", node[j].address, node[j].data, node[j - 1].address);
        }
        printf("%05d %d ", node[i * k].address, node[i * k].data);
        if(i < n / k - 1)
        {
            printf("%05d\n", node[(i + 2) * k].address);
        }else{
            if(n % k == 0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%05d\n", node[(i + 1) * k].address);
                for(int a = (i + 1) * k; a < n; ++a)
                //for(int a = n / k * k; a < n; ++a)
                {
                    printf("%05d %d ", node[a].address, node[a].data);
                    if(a < n - 1)
                        printf("%05d\n", node[a].next);
                    else
                        printf("-1\n");
                }
            }
        }
    }

    return 0;
}




/*
16:25
17:30
18:13
19:26
*/

/*
# test case1:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

# test result1:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/