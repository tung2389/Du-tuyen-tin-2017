#include <bits/stdc++.h>
using namespace std;
vector<long long> adjlist[10000];
vector<long long> cycle;
bool visited[10000];
bool checkcycle[10000];
long long ans=1;
bool check[10000];
vector<long long> vt;
bool scan[10000];
bool IsCycle(long long u,long long start)
{
    if(visited[u])
    {
        if(u==start)
        return true;
        else
        return false;
    }
    visited[u]=1;
    for(long long i=0;i<adjlist[u].size();i++)
    {
        long long v=adjlist[u][i];
        return IsCycle(v,start);
    }
    return false;
}
void dfs(long long u,long long cnt)
{
    if(visited[u]==1)
    {
        if(!check[cnt])
        {
            check[cnt]=1;
            vt.push_back(cnt);
        }
        return;
    }
    visited[u]=1;
    checkcycle[u]=1;
    for(long long i=0;i<adjlist[u].size();i++)
    {
        long long v=adjlist[u][i];
        dfs(v,cnt+1);
    }
}
int main()
{
    long long n;
    cin >> n;
    for(long long i=1;i<=n;i++)
    {
        long long d;
        cin >> d;
        if(i!=d)
        adjlist[i].push_back(d);
    }
    for(long long i=1;i<=n;i++)
    {
        if(adjlist[i].size()>=1)
        {
            if(!IsCycle(i,i))
            {
                cout << "-1" << "\n";
                return 0;
            }
            memset(visited,0,sizeof(visited));
        }
    }
    memset(visited,0,sizeof(visited));
    for(long long i=1;i<=n;i++)
    {
        if(adjlist[i].size()>=1)
        {
        if(!checkcycle[i])
        {
            dfs(i,0);
        }
        }
        else
        {
            checkcycle[i]=1;
        }
        memset(visited,0,sizeof(visited));
    }
    sort(vt.begin(),vt.end(),greater<long long>());
    /*for(int i=0;i<vt.size();i++)
    {
        cout << vt[i] << " ";
    }*/
    for(long long i=0;i<vt.size();i++)
    {
        if(vt[i]%2==0)
            vt[i]=vt[i]/2;
    }
    for(long long i=0;i<vt.size();i++)
    {
        if(!scan[i])
        {
        if(i!=vt.size()-1)
        {
        for(long long j=i+1;j<vt.size();j++)
        {
            if(vt[i]%vt[j]==0)
            {
                scan[j]=1;
            }
        }
        }
        int k=__gcd(ans,vt[i]);
        ans=(ans*vt[i])/k;
        }
    }
    cout << ans << "\n";
}
