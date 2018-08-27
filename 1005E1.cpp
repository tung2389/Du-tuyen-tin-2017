#include <bits/stdc++.h>
using namespace std;
long long lbigger[200010],lsmaller[200010],rbigger[200010],rsmaller[200010],a[200010];
long long ansb[200010],ansm[200010],anse=0;
long long res=1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin >> n >> m;
    long long pos;
    for(long long i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i]==m)
            pos=i;
    }
    for(long long i=pos-1;i>=1;i--)
    {
        if(a[i]>m)
        {
            lbigger[i]=lbigger[i+1]+1;
            lsmaller[i]=lsmaller[i+1];
        }
        else if(a[i]<m)
        {
            lbigger[i]=lbigger[i+1];
            lsmaller[i]=lsmaller[i+1]+1;
        }
    }
    for(long long i=pos+1;i<=n;i++)
    {
        if(a[i]>m)
        {
            rbigger[i]=rbigger[i-1]+1;
            rsmaller[i]=rsmaller[i-1];
        }
        else if(a[i]<m)
        {
            rbigger[i]=rbigger[i-1];
            rsmaller[i]=rsmaller[i-1]+1;
        }
    }
    /*for(long long i=1;i<=pos-1;i++)
    {
        cout << lsmaller[i] << " " << lbigger[i] << "\n";
        cout << "\n";
    }*/
    for(long long i=pos+1;i<=n;i++)
    {
        if(rbigger[i]-rsmaller[i]>0)
        {
            ansb[rbigger[i] - rsmaller[i]]++;
        }
        else if(rbigger[i]-rsmaller[i]<0)
        {
            ansm[rsmaller[i] - rbigger[i]]++;
        }
        else
        {
            anse++;
        }
    }
    for(long long i=1;i<=pos-1;i++)
    {
        if(lsmaller[i]==lbigger[i])
        {
            res+=anse;
            res+=ansb[1];
            res++;
        }
        else if(lbigger[i]==lsmaller[i]+1)
        {
            res+=anse;
            res+=ansm[1];
            res++;
        }
        else if(lsmaller[i]>lbigger[i])
        {
            res+=ansb[lsmaller[i] - lbigger[i]]+ansb[lsmaller[i] - lbigger[i] + 1];
        }
        else if(lsmaller[i]<lbigger[i])
        {
            res+=ansm[lbigger[i] - lsmaller[i] - 1] + ansm[lbigger[i] - lsmaller[i]];
        }
    }
    for(long long i=pos+1;i<=n;i++)
    {
        if(rbigger[i]==rsmaller[i]||rbigger[i]==rsmaller[i]+1)
            res++;
    }
    cout << res << "\n";
}
