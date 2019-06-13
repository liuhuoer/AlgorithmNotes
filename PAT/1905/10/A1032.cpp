#include <cstdio>

const int MAXN = 100010;

struct Node
{
    Node()
    {
        flag = false;
    }
    int address, next;
    char data;
    bool flag;
} node[MAXN];

int main()
{
    // input
    int first_a, first_b, n;
    scanf("%d %d %d", &first_a, &first_b, &n);
    int address, next;
    char data;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d %c %d", &address, &data, &next);
        // wrong use
        //scanf("%d", &address);
        //scanf(" %c %d", &node[address].data, &node[address].next);
        node[address].data = data;
        node[address].next = next;
        node[address].address = address;
    }
    // traversal
    for(int p = first_a; p != -1;)
    {
        node[p].flag = true;
        p = node[p].next;
    }
    int result = MAXN;
    for(int p = first_b; p != -1;)
    {
        if(node[p].flag == true)
        {
            result = p;
            break;
        }
        p = node[p].next;
    }
    // output
    if(result == MAXN)
        printf("-1\n");
    else
        printf("%05d\n", result);
    
    return 0;
}




/*
20:42
21:30
*/

/*
# test case1:
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010

# test result1:
67890

# test result2:
00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1

# test result2:
-1
*/