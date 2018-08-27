#include <bits/stdc++.h>
using namespace std;
int trie_size=0;
int n;
struct node{
    int child[2];
    int have[2];
}trie[16000016];
void update(int num,int val)
{
    int p=0;
    for(int i=30;i>=0;i--)
    {
        int y=((num >> i)&1);
        if(!trie[p].have[y])
        {
            trie[p].child[y]=++trie_size;
        }
        trie[p].have[y]+=val;
        p=trie[p].child[y];
    }
}
int getmax(int num)
{
    int p=0,res=0;
    for(int i=30;i>=0;i--)
    {
        int y=((num >> i)&1);
        if(y==0)
        {
            if(trie[p].have[1])
            {
                p=trie[p].child[1];
                res=res^(1<<i);
            }
            else
            {
                p=trie[p].child[0];
            }
        }
        else
        {
            if(trie[p].have[0])
            {
                p=trie[p].child[0];
            }
            else
            {
                p=trie[p].child[1];
                res=res^(1<<i);
            }
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    update(0,1);
    while(n--)
    {
        char type;
        int num;
        cin >> type >> num;
        if(type=='+')
        {
            update(num,1);
        }
        else if(type=='-')
        {
            update(num,-1);
        }
        else if(type=='?')
        {
            cout << (getmax(num)^num) << "\n";
        }
    }
}
