#include <bits/stdc++.h>
using namespace std;
int triesize=0;
string t[100010];
string ans[100010];
struct query{
	int id, r;
	string s;
}q[100010];
struct node{
	int child[30];
	int nfinish;
}trie[1500010];
bool cmp(query &a,query &b)
{
	return a.r<b.r;
}
void fill(int u)
{
	memset(trie[u].child,0,sizeof(trie[u].child));
	trie[u].nfinish=0;
}
void push(string s)
{
	int p=0;
	for(int i=0;i<s.size();i++)
	{
		if(trie[p].child[s[i]-'a']==0)
		{
			fill(++triesize);
			trie[p].child[s[i]-'a']=triesize;
		}
		p=trie[p].child[s[i]-'a'];
	}
	trie[p].nfinish++;
}
void process(string s,int id)
{
	int p=0;
	for(int i=0;i<s.size();i++)
	{
		if(trie[p].child[s[i]-'a']==0)
		{
			break;
		}
		p=trie[p].child[s[i]-'a'];
		ans[id]+=s[i];
	}
	while(trie[p].nfinish==0)
	{
		for(int i=0;i<26;i++)
		{
			if(trie[p].child[i]!=0)
			{
				p=trie[p].child[i];
				ans[id]+=char(i+'a');
				break;
			}
		}
	}
}
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> t[i];
	}
	int m;
	cin >> m;
	for(int i=1;i<=m;i++)
	{
		cin >> q[i].r >> q[i].s;
		q[i].id=i;
		ans[i]="";
	}
	sort(q+1,q+1+m,cmp);
	int cur=0;
	for(int i=1;i<=m;i++)
	{
		while(cur<q[i].r)
		{
			cur++;
			push(t[cur]);
		}
		process(q[i].s,q[i].id);
	}
	for(int i=1;i<=m;i++)
	{
		cout << ans[i] << "\n";
	}
}
