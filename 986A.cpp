#include <bits/stdc++.h>
using namespace std;

queue<int> q;
vector<int> ans[100010];
vector<int> adjlist[100010];
int dist[100010];
vector<int> product[110];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k,s;
    cin >> n >> m >> k >> s;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        product[x].push_back(i);
    }
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    for(int c=1;c<=k;c++)
    {
        for(int i=1;i<=n;i++)
        {
            dist[i]=999999;
        }
        for(int i=0;i<product[c].size();i++)
        {
            int f=product[c][i];
            dist[f]=0;
            q.push(f);
        }
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int i=0;i<adjlist[u].size();i++)
            {
                int v=adjlist[u][i];
                if(dist[v]<=dist[u]+1) continue;
                q.push(v);
                dist[v]=dist[u]+1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            ans[i].push_back(dist[i]);
        }
        queue<int> emptyq;
        swap(q,emptyq);
    }
    for(int i=1;i<=n;i++)
    {
        nth_element(ans[i].begin(),ans[i].begin()+s,ans[i].end());
        int res=0;
        for(int j=0;j<s;j++)
        {
            res+=ans[i][j];
        }
        cout << res << " ";
    }
}
