#include <bits/stdc++.h>
using namespace std;
double n,m,a[1010],b[1010];
bool check(double mass)
{
    mass-=(double)(mass+m)/a[1];
    if(mass<0.0)
        return false;
    for(int i=2;i<=n;i++)
    {
        mass-=(double)(mass+m)/b[i];
        if(mass<0.0)
            return false;
        mass-=(double)(mass+m)/a[i];
        if(mass<0.0)
            return false;
    }
    mass-=(double)(mass+m)/b[1];
    if(mass<0.0)
        return false;
    return true;
}
double bs()
{
    double l=0,r=(double)1e9;
    while(abs(r-l)>(double)1e-6)
    {
        double mid=(l+r)/2;
        if(check(mid))
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
    }
    return l;
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i]<=1)
        {
            cout << "-1" << "\n";
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin >> b[i];
        if(b[i]<=1)
        {
            cout << "-1" << "\n";
            return 0;
        }
    }
    cout << setprecision(6) << fixed << bs();
}
