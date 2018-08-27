#include <iostream>
using namespace std;
int prev1=10000,prev2=10000;
int pos=0;
int count=0;
int check=0;
int end1,end2;
string s[1000];
int n,m,x,y;
bool visited[1000][1000];
void dfs(int i,int j)
{
	if(i<0||j<0||i>=n||j>=m)
	{
	count=count-1;
	return;
	}
	if(check==1)
	return;
	if(i==end1&&j==end2)
	{
	count++;
	check=1;
	return;
	}
	if(s[i][j]=='1')
	{
	count=count-1;
	return;
	}
	count++;
	if(i==prev1&&j==prev2+1)
	{
		if(pos==1||pos==0)
		pos=2;
	}
	if(i==prev1+1&&j==prev2)
	{
		if(pos==2||pos==0)
		pos=3;
	}
	if(i==prev1&&j==prev2-1)
	{
		if(pos==3||pos==0)
		pos=4;
	}
	if(i==prev1-1&&j==prev2)
	{
		if(pos==4||pos==0)
		pos=1;
	}
	prev1=i;
	prev2=j;
	if(pos==0)
	{
		dfs(i+1,j);
		dfs(i-1,j);
		dfs(i,j+1);
		dfs(i,j-1);
	}
	else if(pos==1)
	{
		dfs(i-1,j);
		dfs(i,j+1);
	}
	else if(pos==2)
	{
		dfs(i,j+1);
		dfs(i+1,j);
	}
	else if(pos==3)
	{
		dfs(i+1,j);
		dfs(i,j-1);
	}
	else if(pos==4)
	{
		dfs(i,j-1);
		dfs(i-1,j);
	}
}
int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> s[i];
	}
	cin >> x >> y;
	cin >> end1 >> end2;
	x=x-1;
	y=y-1;
	end1=end1-1;
	end2=end2-1;
	if(s[x][y]=='1'||s[end1][end2]=='1')
	cout << "NO";
	else
	{
	dfs(x,y);
	cout << count;
	}
}
	
		
