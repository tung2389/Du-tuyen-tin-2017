#include <iostream>
#include <map>
using namespace std;
int sum=0;
bool used[1000][1000];
string s[1000];
map<char,int> p;
int n,m;
void dfs(int a,int b,char c)
{
if(a<0||b<0||a>=n||b>=m)
return;
if(s[a][b]!=c)
{
if(p.count(s[a][b])==0)
{
p[s[a][b]]=1;
sum++;
}
return;
}
if(used[a][b]==1)
return;
used[a][b]=1;
dfs(a+1,b,c);
dfs(a-1,b,c);
dfs(a,b+1,c);
dfs(a,b-1,c);
}
int main()
{
freopen("invin.txt","r",stdin);
freopen("invout.txt","w",stdout);
int ans=0;
cin >> n >> m;
for(int i=0;i<n;i++)
cin >> s[i];
for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
if(used[i][j]==0)
{
sum=0;
dfs(i,j,s[i][j]);
if(sum>ans)
ans=sum;
p.clear();
}
}
}
cout << ans;
}
