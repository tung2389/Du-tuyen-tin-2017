#include <bits/stdc++.h>
using namespace std;
bool p[80];
int main()
{
    long long m,n;
    cin >> m >> n;
    for(long long i=0;i<n;i++)
    {
        cout << "1" << "\n";
        fflush(stdout);
        long long x;
        cin >> x;
        if(x==0||x==-2)
        {
            exit(0);
        }
        if(x==1)
        {
            p[i]=1;
        }
        else
        {
            p[i]=0;
        }
    }
    long long l=2,r=m;
    long long cnt=0;
    while(l<r)
    {
        long long mid=(l+r)/2;
        cout << mid << "\n";
        fflush(stdout);
        long long x;
        cin >> x;
        if(x==0||x==-2)
            exit(0);
        if(p[cnt%n]==1)
        {
            if(x==1)
                l=mid+1;
            else if(x==-1)
                r=mid-1;
        }
        else
        {
            if(x==1)
                r=mid-1;
            else if(x==-1)
                l=mid+1;
        }
        cnt++;
    }
    cout << l << "\n";
    fflush(stdout);
    exit(0);
}
