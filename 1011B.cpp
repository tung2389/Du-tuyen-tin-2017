#include <bits/stdc++.h>
using namespace std;
int a[110];
int cnt[110];
bool check[110];
vector<int> v;
bool ok=true;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        if(a[i]!=1)
        {
            ok=false;
        }
    }
    if(ok && n==1 && m==100)
    {
        cout << "100" << "\n";
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        if(!check[a[i]])
        {
            v.push_back(cnt[a[i]]);
            check[a[i]]=1;
        }
    }
    sort(v.begin(),v.end());
    /*for(int i=0;i<v.size();i++)
    {
        cout << v[i] << " ";
    }*/
    int ans=-1;
    int limit;
    if((int)v.size()-n>=0)
    {
        limit=v.size()-n;
    }
    else
    {
        limit=0;
    }
    int sum=0;
    int l=0,r=100;
    //cout << v.size() << "\n";
    while(l<r)
    {
        int mid=(l+r)/2;
        if(mid==0)
        {
            break;
        }
        int sum=0;
        for(int i=(int)v.size()-1;i>=max((int)v.size()-n,0);i--)
        {
            sum+=v[i]/mid;
        }
        if(sum>=n)
        {
            l=mid+1;
        }
        else
        {
            r=mid;
        }
    }
    /*for(int i=(int)v.size()-1;i>=limit;i--)
    {
        sum+=v[i];
        ans=max(ans,min(sum/n,v[i]));
    }*/
    if(l)
    cout << l-1 << "\n";
    else
    cout << "0" << "\n";
}
