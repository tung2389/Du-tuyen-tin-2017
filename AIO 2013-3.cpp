#include <iostream>
using namespace std;
int count=0,ans=0,n,m;
string s[10000];
bool visited[10000][10000];
void dfs(int x,int y)
{
if(x<0||y<0||x>=n||y>=m||s[x][y]=='.') 
{
count=0;
return;
}
if(visited[x][y]==1)
{
count=0;
return;
}
visited[x][y]=1;
if(x<n-1&&y<m-1)
{
if(s[x+1][y+1]=='X')
{
count++;
ans=max(ans,count);
dfs(x+1,y+1);
}
}
if(x>0&&y>0)
{
if(s[x-1][y-1]=='X')
{
count++;
ans=max(ans,count);
dfs(x-1,y-1);
}
}
if(x>0&&y<m-1)
{
if(s[x-1][y+1]=='X')
{
count++;
ans=max(ans,count);
dfs(x-1,y+1);
}
}
if(y>0&&x<n-1)
{
if(s[x+1][y-1]=='X')
{
count++;
ans=max(ans,count);
dfs(x+1,y-1);
}
}
if(x<n-1)
{
if(s[x+1][y]=='X')
{
count++;
ans=max(ans,count);
dfs(x+1,y);
}
}
if(x>0)
{
if(s[x-1][y]=='X')
{
count++;
ans=max(ans,count);
dfs(x-1,y);
}
}
if(y<m-1)
{
if(s[x][y+1]=='X')
{
count++;
ans=max(ans,count);
dfs(x,y+1);
}
}
if(y>0)
{
if(s[x][y-1]=='X')
{
count++;
ans=max(ans,count);
dfs(x,y-1);
}
}

}
int main()
{
cin >> n >> m;
for(int i=0;i<n;i++)
{
	for(int j=0;j<m;j++)
	{
		visited[i][j]=0;
	}
}
for(int i=0;i<n;i++)
cin >> s[i];
for(int i=0;i<n;i++)
{
   for(int j=0;j<m;j++)
   {
       if(s[i][j]=='X')
       dfs(i,j);
   }
}
cout << ans;
}
