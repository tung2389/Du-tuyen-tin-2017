#include <iostream>
using namespace std;
string s[1000];
int n,m,count=0;
char a;
void dfs(int i,int j)
{
	if(j>0)
	{
	if(s[i][j-1]=='>')
	{
		count++;
		dfs(i,j-1);
	}
	}
	if(i>0)
	{
	if(s[i-1][j]=='v')
	{
		count++;
		dfs(i-1,j);
	}
	}
	else
	return;
}
int main()
{
	freopen("surfin.txt","r",stdin);
	freopen("surfout.txt","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
	cin >> s[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			
			if(s[i][j]=='*')
			{
				count++;
				dfs(i,j);
			}
			}
			}
			cout << count;
			}
				
	
