#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <string>

using namespace std;

void query(map<string, set<int>> mp, string str)
{
    if(mp.find(str) == mp.end())
       printf("Not Found\n");
    else{
       for(auto beg = mp[str].begin(); beg != mp[str].end(); ++beg)
       {
           printf("%07d\n", *beg);
       }
    }
}

int main()
{
    int n, id;
    string title, author, keys, publisher, year;
    char c;
    map<string, set<int>> tit2id, aut2id, key2id, pub2id, yea2id;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &id);
        getchar();      // remove enter
        getline(cin, title);
        tit2id[title].insert(id);
        getline(cin, author);
        aut2id[author].insert(id);
        while(cin >> keys)
        {
            key2id[keys].insert(id);
            c = getchar();
            if(c == '\n')
                break;
        }
        getline(cin, publisher);
        pub2id[publisher].insert(id);
        getline(cin, year);
        yea2id[year].insert(id);
    }

    // query
    int m, num;
    string str;
    scanf("%d", &m);
    for(int i = 0; i < m; ++i)
    {
        scanf("%d:", &num);
        getline(cin, str);
        //cin >> num >> ":" >> str;
        switch(num)
        {
            case 1:
                query(tit2id, str);
                break;
            case 2:
                query(aut2id, str);
                break;
            case 3:
                query(key2id, str);
                break;
            case 4:
                query(pub2id, str);
                break;
            case 5:
                query(yea2id, str);
                break;
        }
    }

    return 0;
}




/*
8:37
10:10
*/

/*
# test case1:
3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1:The Testing Book
2:Yue Chen
3:keywords
4:ZUCS Print
5:2011
3:blablabla


# test result1:
1:The Testing Book
1111111
2222222
2:Yue Chen
1111111
3333333
3:keywords
1111111
2222222
3333333
4:ZUCS Print
1111111
5:2011
1111111
2222222
3:blablabla
Not Found
*/