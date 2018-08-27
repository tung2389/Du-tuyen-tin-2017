#include <bits/stdc++.h>
using namespace std;
long long a[100010];
bool del[100010];
long long ans=0;
vector<long long> v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long minn=9999999999;
    long long n,k,l;
    cin >> n >> k >> l;
    for(long long i=1;i<=n*k;i++)
    {
        cin >> a[i];
        minn=min(minn,a[i]);
    }
    long long maxx=minn+l;
    sort(a+1,a+1+n*k);
    if(k==1)
    {
        if(a[n*k]>maxx)
        {
            cout << "0" << "\n";
            return 0;
        }
        long long sum=0;
        for(long long i=1;i<=n*k;i++)
        {
            sum+=a[i];
        }
        cout << sum << "\n";
    }
    else
    {
    long long pos=1;
    for(long long i=n*k;i>=1;i--)
    {
        if(a[i]<=maxx)
        {
            pos=i;
            maxx=a[i];
            break;
        }
    }
    if(pos<n)
    {
        cout << "0" << "\n";
        return 0;
    }
    //cout << pos << " " << maxx << "\n";
    long long numbig=n*k-pos;
    long long cnt=numbig/(k-1);
    long long precnt=cnt;
    cnt=cnt*(k-1);
    for(long long i=n*k;i>n*k-cnt;i--)
    {
        del[i]=1;
    }
    for(long long i=pos;i>pos-precnt;i--)
    {
        del[i]=1;
        ans+=a[i];
    }
    long long left=numbig-cnt;
    if(left>0)
    {
    for(long long i=pos-precnt;i>pos-precnt-(k-left);i--)
    {
        del[i]=1;
    }
    ans+=a[pos-precnt-(k-left)+1];
    }
    for(long long i=1;i<=pos;i++)
    {
        if(!del[i])
        {
            v.push_back(a[i]);
        }
    }
    if(v.size()<k)
    {
        if(v.size()>0)
        {
        ans+=v[0];
        }
    }
    else
    {
        long long curpos=0;
        long long curval=v[0];
        for(long long i=0;i<v.size();i++)
        {
            if(i==v.size()-1)
            {
                ans+=curval;
            }
            else if(curpos==k)
            {
                ans+=curval;
                curpos=0;
                curval=v[i];
            }
            curpos++;
        }
    }
    cout << ans << "\n";
    }
}
