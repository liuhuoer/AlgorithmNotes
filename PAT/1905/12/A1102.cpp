#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 12;
int n, numLevel = 0, numIn = 0;

struct Node
{
    int left, right;
};

vector<Node> dics;
bool noRoot[MAXN] = {false};

int c2i(char c)
{
    int res;
    if(c == '-')
        res = -1;
    else
    {
        res = c - '0';
        noRoot[res] = true;
    }
    return res;
    
}

int findRoot()
{
    int i = 0, sz = dics.size();
    for(; i < sz; ++i)
    {
        if(noRoot[i] == false)
            break;
    }
    return i;
}

void postOrder(int root)
{
    if(root == -1)
        return;
    postOrder(dics[root].left);
    postOrder(dics[root].right);
    swap(dics[root].left, dics[root].right);
}

void levelOrder(int root)
{
    queue<int> qn;
    qn.push(root);
    int t;
    while(!qn.empty())
    {
        t = qn.front();
        qn.pop();
        printf("%d", t);
        ++numLevel;
        if(numLevel < n)
            printf(" ");
        if(dics[t].left != -1)
            qn.push(dics[t].left);
        if(dics[t].right != -1)
            qn.push(dics[t].right);
    }
}

void inOrder(int root)
{
    if(root == -1)
        return;
    inOrder(dics[root].left);
    printf("%d", root);
    ++numIn;
    if(numIn < n)
        printf(" ");
    inOrder(dics[root].right);
}

int main()
{
    scanf("%d", &n);
    char a, b;
    Node tmp;
    for(int i = 0; i < n; ++i)
    {
        scanf("%*c%c %c", &a, &b);
        tmp.left = c2i(a);
        tmp.right = c2i(b);
        dics.push_back(tmp);
    }
    // findRoot
    int root = findRoot();
    // reverse
    postOrder(root);
    // output
    levelOrder(root);
    printf("\n");
    inOrder(root);

    return 0;
}




/*
15:33
14:45
*/

/*
Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:
3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1
*/
