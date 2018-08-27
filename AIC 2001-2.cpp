#include<iostream>
using namespace std;
int n,m;
bool used[101][101];
string s[101];
int ans;
int sum;
bool check;
void dfs(int a,int b)
{
	if(a<0 || b<0 || a >=n || b>=m) return;
	if(used[a][b]==1 || s[a][b]=='#') return;
	used[a][b]=1;
	ans++;
	for(int i=-1 ; i<=1 ; i++)
		for(int j=-1 ; j<=1 ; j++)
			dfs(a+i,b+j);
}
int main(){
	freopen("cartin.txt","r",stdin);
	freopen("cartout.txt","w",stdout);
	cin>>m>>n;
	
	int i,j;
	for(i=0 ; i<n ; i++)
	{
		cin>>s[i];
	}
	ans=0;
	for(i=0 ; i<n ; i++)
	{
		if(s[i][0]=='.'&&used[i][0]==0)
		dfs(i,0);
		if(s[i][m-1]=='.'&&used[i][m-1]==0)
		dfs(i,m-1);
	}
	for(j=0 ; j<m ; j++)
	{
		if(s[0][j]=='.'&&used[0][j]==0)
		dfs(0,j);
		if(s[n-1][j]=='.'&&used[n-1][j]==0)
		dfs(n-1,j);
	}
	ans=m*n-ans;
	cout<<ans;
}
