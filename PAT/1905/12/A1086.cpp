#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

const int MAXN = 35;

int n, num;     // n is number of all value, num is used to verify
vector<int> pre, in;

struct Node
{
    int key;
    Node * left;
    Node * right;
};

int getNum(string str)
{
    int k = str.size();
    int res;
    if(str[k - 2] != ' ')
        res = (str[k - 2] - '0') * 10 + str[k - 1] - '0';
    else
        res = str[k - 1] - '0';
    return res;
}

Node * create(int preL, int preR, int inL, int inR)
{
    if(preL > preR || inL > inR)
    {
        return NULL;
    }
    Node * node = new Node;
    node->key = pre[preL];

    int k = inL;
    for(; k < inR; ++k)
    {
        if(in[k] == node->key)
            break;
    }
    int numleft = k - inL;
    node->left = create(preL + 1, preL + numleft, inL, k - 1);
    node->right = create(preL + numleft + 1, preR, k + 1, inR);
    return node;
}

void postorder(Node * node)
{
    if(node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    ++num;
    printf("%d", node->key);
    if(num < n)
        printf(" ");
}

int main()
{
    // input
    scanf("%d", &n);
    getchar();
    string str;
    int tmp;
    stack<int> ti;
    for(int i = 0; i < 2 * n; ++i)
    {
        getline(cin, str);
        if(str != "Pop")
        {
            tmp = getNum(str);
            ti.push(tmp);
            pre.push_back(tmp);
        }else{
            in.push_back(ti.top());
            ti.pop();
        }
    }

    // create binary tree
    Node * root = create(0, n - 1, 0, n - 1);

    // postorder
    postorder(root);

    return 0;
}



/*
20:40
21:38
*/

/*
Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:
3 4 2 6 5 1
*/