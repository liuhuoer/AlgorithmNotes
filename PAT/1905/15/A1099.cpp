#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 105;
int n, origin[MAXN], index = 0;
int in[MAXN], level[MAXN];

struct Node
{
    int key, left, right;
} nodes[MAXN];

void inOrder(int root)
{
    if(root == -1)
        return;
    inOrder(nodes[root].left);
    nodes[root].key = origin[index++];
    inOrder(nodes[root].right);
}

void levelOrder(int root)
{
    queue<int> qi;
    qi.push(root);
    for(int i = 0; !qi.empty(); ++i)
    {
        int tmp = qi.front();
        qi.pop();
        printf("%d", nodes[tmp].key);
        if(i != n - 1)
            printf(" ");
        if(nodes[tmp].left != -1)
            qi.push(nodes[tmp].left);
        if(nodes[tmp].right != -1)
            qi.push(nodes[tmp].right);
    }

}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d %d", &nodes[i].left, &nodes[i].right);
    }
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &origin[i]);
    }
    sort(origin, origin + n);
    inOrder(0);
    levelOrder(0);

    return 0;
}




/*
21:23
22:45
*/

/*
Sample Input:
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
Sample Output:
58 25 82 11 38 67 45 73 42
*/