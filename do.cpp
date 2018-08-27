#include <iostream>
using namespace std;

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,1,-1};
int cnt,maxx[100],minn[100],n,m,ans=-100000;
struct point
{
    int x,y;
    point(){}
    point(int _,int __){x = _; y = __;}
}p[10000];
bool visited[1000][1000];
char s[1000][1000];
bool check(int x,int y){return !(x < 1 || y < 1 || x > n || y > m || visited[x][y] || s[x][y] == '.');}
void dfs(int x,int y)
{
visited[x][y]=true;
p[++cnt]=point(x,y);
for(int i=0;i<4;i++)
{
x=x+dx[i];
y=y+dy[i];
if(x<1||y<1||x>n||y>m||s[x][y]=='.')
return;
else{
if(visited[x][y]==false)
dfs(x,y);
}
}
}
void getans()
{
    int i,j,k,t,s;
    for(i = 0; i < 4; ++ i)
        maxx[i] = -1000000, minn[i] = 1000000;
    for(i = 1; i <= cnt; ++ i)
    {
    
        for(j = 0; j < 4; ++ j)
        {
            if(j==0)
            s=-p[i].x-p[i].y;
            if(j==1)
            s=p[i].x-p[i].y;
            if(j==2)
            s=p[i].y-p[i].x;
            if(j==3)
            s=p[i].x+p[i].y;
            maxx[j] = max(maxx[j], s);
            minn[j] = min(minn[j], s);
        }

    }
    for(i = 0; i < 4; ++ i)
        if(maxx[i] - minn[i] > ans)
            ans = maxx[i] - minn[i];
}
 
 
void work(int x,int y)
{
    int i;
    cnt = 0;
    dfs(x,y);
    getans();
}
int main()
{

    cin >> n >> m;
    for(int i = 1; i <= n; ++ i)
    {
    for(int j=1;j<=m;j++)
    {
        cin >> s[i][j];
    }
    }
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            if(!visited[i][j] && s[i][j] == 'X')
                work(i,j);
    cout << ans;
}
