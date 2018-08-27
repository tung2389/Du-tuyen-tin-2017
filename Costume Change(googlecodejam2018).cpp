#include <bits/stdc++.h>
using namespace std;
int n,t=0;
int match[210];
int visited[210];
vector<int> adjlist[210];
int board[210][210];
bool dfs(int u)
{
    visited[u]=t;
    for(int i=0;i<adjlist[u].size();i++)
    {
        int v=adjlist[u][i];
        if(!match[v] || (visited[match[v]]!=t && dfs(match[v])))
        {
            match[u]=v;
            match[v]=u;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int num;
    cin >> num;
    int k=1;
    while(num--)
    {
        int ans=0;
        int n;
        cin >> n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin >> board[i][j];
            }
        }
        for(int color=-n;color<=n;color++)
        {
            int cnt=0,res=0;
            for(int i=0;i<=2*n;i++)
            {
                adjlist[i].clear();
                match[i]=0;
                visited[i]=0;
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(board[i][j]==color)
                    {
                        adjlist[i].push_back(j+n);
                        adjlist[j+n].push_back(i);
                        cnt++;
                    }
                }
            }
            for(int i=1;i<=n;i++)
            {
                t++;
                dfs(i);
            }
            for(int i=1;i<=n;i++)
            {
                if(match[i]!=0)
                    res++;
            }
            ans+=(cnt-res);
        }
        cout << "Case #" << k << ": " << ans << "\n";
        k++;
    }
}
