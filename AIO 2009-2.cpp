#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
int ans=0;
int n,m;
char s[2000][2000];
bool visited[2000][2000];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool check(int x,int y)
{
return x<1||y<1||x>n||y>m||visited[x][y]||s[x][y]=='#';
}
void bfs(int x,int y)
{
queue<pair<int,int> > q;
pair<int,int> head,next;
visited[x][y]=true;
bool test;
head=make_pair(x,y);
q.push(head);
while(!q.empty())
{
head=q.front();
q.pop();
test=false;
for(int i=0;i<4;i++)
{
next = make_pair(head.first+dx[i],head.second+dy[i]);
if(check(next.first,next.second)==false)
{
visited[next.first][next.second]=true;
q.push(next);
test=true;
}
}
if(test==false) //het duong la test=false;
ans++;
}
}
int main()
{
freopen("cavein.txt","r",stdin);
freopen("caveout.txt","w",stdout);
cin >> n >> m;
for(int i=1;i<=n;i++)
{
for(int j=1;j<=m;j++)
{
cin >> s[i][j];
}
}
bfs(1,1);
cout << ans;
}


