#include <cstdio>
#include <algorithm>

using namespace std;

int n;

struct Node
{
    int key, Heg;
    Node * lc, * rc;
} *root;

Node * newNode(int value)
{
    Node * node = new Node();
    node->key = value;
    node->Heg = 1;
    node->lc = NULL;
    node->rc = NULL;
    return node;
}

int getHeg(Node * node)
{
    if(node == NULL)
        return 0;
    else
        return node->Heg;
}

void UpdateHeg(Node * node)
{
    node->Heg =  max(getHeg(node->lc), getHeg(node->rc)) + 1;
}

int getBalanceHeg(Node * node)
{
    return getHeg(node->lc) - getHeg(node->rc);
}

void L(Node * & node)
{
    Node * tmp = node->rc;
    node->rc = tmp->lc;
    tmp->lc = node;
    UpdateHeg(node);
    UpdateHeg(tmp);
    node = tmp;
}

void R(Node * & node)
{
    Node * tmp = node->lc;
    node->lc = tmp->rc;
    tmp->rc = node;
    UpdateHeg(node);
    UpdateHeg(tmp);
    node = tmp;
}

void insert(Node * & node, int value)
{
    if(node == NULL)
    {
        node = newNode(value);
        return;
    }
    if(value < node->key)
    {
        insert(node->lc, value);
        UpdateHeg(node);
        if(getBalanceHeg(node) == 2)
        {
            if(getBalanceHeg(node->lc) == 1)
            {
                R(node);
            }
            else if(getBalanceHeg(node->lc) == -1)
            {
                L(node->lc);
                R(node);
            }
        }
    }else{
        insert(node->rc, value);
        UpdateHeg(node);
        if(getBalanceHeg(node) == -2)
        {
            if(getBalanceHeg(node->rc) == -1)
            {
                L(node);
            }
            else if(getBalanceHeg(node->rc) == 1)
            {
                R(node->rc);
                L(node);
            }
        }
    }

}


int main()
{
    scanf("%d", &n);
    int tmp;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);
        insert(root, tmp);
    }
    printf("%d", root->key);

    return 0;
}




/*
9:20
10:15
10:46
13:39
*/


/*
Sample Input 1:
5
88 70 61 96 120
Sample Output 1:
70
Sample Input 2:
7
88 70 61 96 120 90 65
Sample Output 2:
88
*/
