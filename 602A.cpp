#include <bits/stdc++.h>
using namespace std;
long long poww(long long x,long long n)
{
    long long res=1;
    while(n)
    {
        if(n%2==1)
            res=res*x;
        x=x*x;
        n=n/2;
    }
    return res;
}
int main()
{
    long long n,k,d;
    cin >> n >> k;
    long long sum1=0,sum2=0;
    long long poww1=poww(k,n-1);
    for(long long i=1;i<=n;i++)
    {
        cin >> d;
        sum1+=d*poww1;
        poww1=poww1/k;
    }
    cin >> n >> k;
    long long poww2=poww(k,n-1);
    for(long long i=1;i<=n;i++)
    {
        cin >> d;
        sum2+=d*poww2;
        poww2=poww2/k;
    }
    if(sum1==sum2)
        cout << "=" << "\n";
    else if(sum1>sum2)
        cout << ">" << "\n";
    else
        cout << "<" << "\n";
}
