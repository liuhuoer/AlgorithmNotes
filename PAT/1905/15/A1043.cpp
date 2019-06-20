#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1010;

struct Node
{
    Node()
    {
        key = 0;
        left = NULL;
        right = NULL;
    }
    int key;
    Node * left, * right;
} nodes[MAXN];

void insert(Node * &root, int key)
{
    if(root == NULL)
    {
        root = new Node();
        root->key = key;
        return;
    }
    if(key < root->key)
        insert(root->left, key);
    else
        insert(root->right, key);
}

void preOrder(Node * root, vector<int> & vi)
{
    if(root == NULL)
        return;
    vi.push_back(root->key);
    preOrder(root->left, vi);
    preOrder(root->right, vi);
}

void preOrderM(Node * root, vector<int> & vi)
{
    if(root == NULL)
        return;
    vi.push_back(root->key);
    preOrderM(root->right, vi);
    preOrderM(root->left, vi);
}

void postOrder(Node * root, vector<int> & vi)
{
    if(root == NULL)
        return;
    postOrder(root->left, vi);
    postOrder(root->right, vi);
    vi.push_back(root->key);
}


void postOrderM(Node * root, vector<int> & vi)
{
    if(root == NULL)
        return;
    postOrderM(root->right, vi);
    postOrderM(root->left, vi);
    vi.push_back(root->key);
}

vector<int> original, pre, preM, post, postM;

int main()
{
    int n;
    scanf("%d", &n);
    Node * root = NULL;
    for(int i = 0, data; i < n; ++i)
    {
        scanf("%d", &data);
        original.push_back(data);
        insert(root, data);
    }
    preOrder(root, pre);
    preOrderM(root, preM);
    postOrder(root, post);
    postOrderM(root, postM);
    if(original == pre)
    {
        printf("YES\n");
        for(int i = 0; i < post.size(); ++i)
        {
            printf("%d", post[i]);
            if(i != post.size() - 1)
                printf(" ");
        }
    }else if(original == preM){
        printf("YES\n");
        for(int i = 0; i < postM.size(); ++i)
        {
            printf("%d", postM[i]);
            if(i != postM.size() - 1)
                printf(" ");
        }
    }else
    {
        printf("NO\n");
    }
    

    return 0;
}




/*
11:30
12:56
*/

/*
Sample Input 1:
7
8 6 5 7 10 8 11
Sample Output 1:
YES
5 7 6 8 11 10 8
Sample Input 2:
7
8 10 11 8 6 7 5
Sample Output 2:
YES
11 8 10 7 5 6 8
Sample Input 3:
7
8 6 8 5 10 9 11
Sample Output 3:
NO
*/