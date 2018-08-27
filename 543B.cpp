#include <bits/stdc++.h>
using namespace std;
int d[3010][3010];
vector<int> adjlist[3010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    int s1,t1,l1,s2,l2,t2;
    cin >> s1 >> t1 >> l1;
    cin >> s2 >> t2 >> l2;
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        q.push(i);
        d[i][i]=0;
        int cnt=0;
        while(!q.empty())
        {
            cnt++;
            int sizee=q.size();
            for(int t=0;t<sizee;t++)
            {
            int u=q.front();
            q.pop();
            for(int k=0;k<adjlist[u].size();k++)
            {
                int v=adjlist[u][k];
                if(d[i][v]==0 && v!=i)
                {
                d[i][v]=cnt;
                q.push(v);
                }
            }
            }
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout << i << " " << j << " " << d[i][j] << "\n";
        }
    }*/
    int ans=999999;
    for(int k=1;k<=2;k++)
    {
        swap(s1,t1);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int d1=d[s1][i] + d[i][j] + d[j][t1];
                int d2=d[s2][i] + d[i][j] + d[j][t2];
                if(d1 <= l1 && d2 <= l2)
                {
                    ans=min(ans,d1 + d2 - d[i][j]);
                }
            }
        }
    }
    if(d[s1][t1] <= l1 && d[s2][t2] <= l2)
    {
        ans=min(ans,d[s1][t1] + d[s2][t2]);
    }
    if(ans>m)
    {
        cout << "-1" << "\n";
    }
    else
    {
        cout << m-ans << "\n";
    }
}
