#include <bits/stdc++.h>
using namespace std;
int cnt[28];
string s;
int dp[3000][3000];
string tr="";
int cnt100=0;
void trace(int x,int y)
{
	if(cnt100<100)
	{
	if(x==y)
	{
		tr=tr+s[x];
	}
	else
	{
	if(y==x+1)
	{
		if(s[x]==s[y]) tr=s[x]+tr+s[y];
		else
		tr=tr+s[y];
	}
    else
    {
	if(s[x]==s[y] && dp[x][y+1-x]==dp[x+1][y-1-x]+2)
	{
		cnt100+=2;
		trace(x+1,y-1);
		tr=s[x]+tr+s[y];
	}
	else if(dp[x][y-x+1]==dp[x+1][y-x])
	trace(x+1,y);
	else if(dp[x][y-x+1]==dp[x][y-x])
	trace(x,y-1);
}
}
}
}
int main()
{
	cin >> s;
	char c;
	bool ok=false;
	for(int i=0;i<s.size();i++)
	{
	dp[i][1]=1;
	dp[i][0]=0;
	cnt[s[i]-'a']++;
	if(cnt[s[i]-'a']>=100)
	{
		ok=true;
		c=s[i];
		break;
	}
    }
    if(ok)
    {
    	for(int i=0;i<100;i++)
    	{
    		cout << c;
		}
		return 0;
	}
	int maxx=0,posi,posj;
	string s1="",s2="";
	for(int i=s.size()-1;i>=0;i--)
	{
		for(int j=2;j<s.size()+1-i;j++)
		{
			if(s[i]==s[i+j-1])
			{
				dp[i][j]=dp[i+1][j-2]+2;
			}
			else
			{
				dp[i][j]=max(dp[i+1][j-1],dp[i][j-1]);
			}
			if(dp[i][j]>maxx)
			{
				maxx=dp[i][j];
				posi=i;
				posj=i+j-1;
			}
		}
	}
	//cout << maxx;
	trace(posi,posj);
	if(cnt100==0)
	cout << s[0];
	else
	cout << tr;
}
