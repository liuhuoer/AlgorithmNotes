#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 100010;
set<int> dics;

struct Node
{
    int address, key, next;
} node[MAXN];

bool find(int a)
{
    if(dics.find(a) != dics.end())
        return true;
    return false;
}

int main()
{
    int first, n;
    int address, key, next;
    // input
    cin >> first >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> address >> key >> next;
        node[address].address = address;
        node[address].key = key;
        node[address].next = next;
    }

    // traversal
    int p = first, ab;
    vector<Node> vn_real, vn_fake;
    while(p != -1)
    {
        ab = abs(node[p].key);
        if(find(ab))
            vn_fake.push_back(node[p]);
        else
            vn_real.push_back(node[p]);
        dics.insert(abs(ab));
        
        p = node[p].next;
    }
    // output
    for(auto begin = vn_real.begin(); begin != vn_real.end(); ++begin)
    {
        begin->next = (begin + 1)->address;
        printf("%05d %d ", begin->address, begin->key);
        if(begin != (vn_real.end() - 1))
            printf("%05d\n", begin->next);
        else
            printf("-1\n");
    }
    for(auto begin = vn_fake.begin(); begin != vn_fake.end(); ++begin)
    {
        begin->next = (begin + 1)->address;
        printf("%05d %d ", begin->address, begin->key);
        if(begin != (vn_fake.end() - 1))
            printf("%05d\n", begin->next);
        else
            printf("-1\n");
    }

    return 0;
}




/*
15:55
16:41
*/

/*
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
*/

/*
00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1
*/
