#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int in[35], post[35];
int n;

struct Node
{
    int key;
    Node * lchild;
    Node * rchild;
};

Node* create(int postL, int postR, int inL, int inR)
{
    if(postL > postR || inL > inR)
        return NULL;
    Node * node = new Node;
    node->key = post[postR];
    int k = inL;
    for(; k < inR; ++k)
    {
        if(in[k] == node->key)
            break;
    }
    int leftNum = k - inL;
    node->lchild = create(postL, postL + leftNum - 1, inL, k - 1);
    node->rchild = create(postL +leftNum, postR - 1, k + 1, inR);
    return node;
}

void BFS(Node * nod)
{
    queue<Node*> qn;
    qn.push(nod);
    int num = 0;
    while(!qn.empty())
    {
        Node* now = qn.front();
        qn.pop();
        ++num;
        printf("%d", now->key);
        if(num < n)
            printf(" ");
        if(now->lchild != NULL)
            qn.push(now->lchild);
        if(now->rchild != NULL)
            qn.push(now->rchild);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &post[i]);
    }
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &in[i]);
    }
    Node * root = create(0, n - 1, 0, n - 1);
    BFS(root);

    return 0;
}



/*
11:58
13:11
*/

/*
Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 2
*/