#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n,m,k;
int P[100005][22];
int h[100005];
vector<int> AdjList[100010];
int visited[100005];
vector<int> buffer;
vector<int> ans(100005);

void DFS(int u,int parent)
{
    P[u][0] = parent;
    for(int i=0;i<AdjList[u].size();i++)
    {
        int v = AdjList[u][i];
        if(v!=parent)
        {
            h[v] = h[u] + 1;
            DFS(v,u);
        }
    }
}


int LCA(int u,int v)
{
    if(h[u]<h[v])
        swap(u,v);

    for(int i=20;i>=0;i--)
    {
        if(h[P[u][i]]>=h[v])
            u = P[u][i];
    }
    if(u==v)
        return u;

    for(int i=20;i>=0;i--)
    {
        if(P[u][i]!=P[v][i])
        {
            u = P[u][i];
            v = P[v][i];
        }
    }

    return P[u][0];
}

void built_tree()
{
    for(int i=1;i<=n;i++)
    {
        if(P[i][0]<=0)
        {
            h[i] = 0;
            DFS(i,i);
        }
    }

    for(int j=1;j<=20;j++)
    {
        for(int i=1;i<=n;i++)
            P[i][j] = P[P[i][j-1]][j-1];
    }
}

void bfs()
{
    memset(visited,0,sizeof(visited));
    queue<pair<int,int>> q;
    for(int i=0;i<buffer.size();i++)
        q.push(make_pair(buffer[i],0));
    buffer.clear();
    while(!q.empty())
    {
        ii u = q.front();
        q.pop();
        visited[u.first] = 1;
        ans[u.first] = min(ans[u.first],u.second);
        for(int i=0;i<AdjList[u.first].size();i++)
        {
            int v = AdjList[u.first][i];
            if(visited[v]==0)
            {
                q.push(make_pair(v,u.second+1));
                visited[v] = 1;
            }
        }
    }
}

int dis(int u,int v)
{
    int p = LCA(u,v);
    return h[u]+h[v]-2*h[p];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    k = sqrt(m);
    for(int i=2;i<=n;i++)
        ans[i] = 2e9;
    int x,y;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        AdjList[x].push_back(y);
        AdjList[y].push_back(x);
    }
    built_tree();
    buffer.push_back(1);
    int type;
    int cnt  = 0;
    while(m--)
    {
        cin>>type;
        if(type==2)
        {
            cin>>type;
            for(int i=0;i<buffer.size();i++)
            {
                ans[type] = min(ans[type],dis(type,buffer[i]));
            }
            //cout<<'\n';
            cout<<ans[type]<<'\n';
        }
        else
        {
            cin>>type;
            cnt++;
            if(cnt==k)
            {
                buffer.push_back(type);
                bfs();
                cnt = 0;
            }
            else
                buffer.push_back(type);
        }
    }
}
