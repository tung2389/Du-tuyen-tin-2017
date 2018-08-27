
#include <bits/stdc++.h>
using namespace std;
 
const int N = 1005;
const int INF = 1<<30;
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,1,-1};
 
char ar[N][N];
int n,m,ans;
bool col[N][N];
int maxx[5],minn[5];
 
int cnt;
struct point
{
    int x,y;
    point(){}
    point(int _,int __){x = _; y = __;}
}p[N*N];
 
bool check(int x,int y){return !(x < 1 || y < 1 || x > n || y > m || col[x][y] || ar[x][y] == '.');}
 
queue<point> q;
 
void bfs(int x,int y)
{
    q.push(point(x,y));
    point head,next;
    int i;
    col[x][y] = true;
    while(!q.empty())
    {
        head = q.front();
        q.pop();
        p[++cnt] = point(head.x,head.y);
        for(i = 0 ; i < 4; ++ i)
        {
            next = point(head.x+dx[i], head.y+dy[i]);
            if(check(next.x,next.y)) q.push(next), col[next.x][next.y] = true;
        }
    }
}
 
void getans()
{
    int i,j,k,t,s,tmp = 4;
    for(i = 0; i < tmp; ++ i)
        maxx[i] = -INF, minn[i] = INF;
    for(i = 1; i <= cnt; ++ i)
    {
        for(j = 0; j < tmp; ++ j)
        {
            t = j; s = 0;
            if(t&1) s += p[i].x;
            else s -= p[i].x;
            t >>= 1;
            if(t&1) s += p[i].y;
            else s -= p[i].y;
            maxx[j] = max(maxx[j], s);
            minn[j] = min(minn[j], s);
        }
    }
    for(i = 0; i < tmp; ++ i)
        if(maxx[i] - minn[i] > ans)
            ans = maxx[i] - minn[i];
}
 
void work(int x,int y)
{
    int i;
    cnt = 0;
    bfs(x,y);
    getans();
}
 
int main()
{
    int i,j,a,b;
    freopen("artin.txt","r",stdin);
    freopen("artout.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(i = 1; i <= n; ++ i)
        scanf("%s",ar[i]+1);
    ans = -INF;
    for(i = 1; i <= n; ++ i)
        for(j = 1; j <= m; ++ j)
            if(!col[i][j] && ar[i][j] == 'X')
                work(i,j);
    printf("%d",ans);
    return 0;
}
