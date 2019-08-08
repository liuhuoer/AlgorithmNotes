#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100010;

struct Node
{
    Node()
    {
        key = MAXN;
        flag = false;
    }
    int address, key, next;
    bool flag;
} node[MAXN];

bool cmp(Node a, Node b)
{
    if(a.flag == false || b.flag == false)
        return a.flag > b.flag;
    else
        return a.key < b.key;
}

int main()
{
    // input
    int n, first;
    scanf("%d %d", &n, &first);
    int address;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &address);
        scanf("%d%d", &node[address].key, &node[address].next);
        node[address].address = address;
    }

    // traversal
    int count = 0;
    for(int p = first; p != -1;)
    {
        node[p].flag = true;
        ++count;
        p = node[p].next;
    }

    // output
    if(count == 0)
    {
        printf("0 -1");
    }else{
        // sort
        sort(node, node + MAXN, cmp);
        first = node[0].address;

        printf("%d %05d\n", count, first);
        for(int i = 0; i < count; ++i)
        {
            printf("%05d %d ", node[i].address, node[i].key);
            if(i != count - 1)
            {
                node[i].next = node[i + 1].address;
                printf("%05d\n", node[i].next);
            }
            else
            {
                node[i].next = -1;
                printf("-1\n");
            }
        }
    }
   return 0;
}




/*
21:39
22:10
*/

/*
# test case1:
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345

# test result1:
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
*/