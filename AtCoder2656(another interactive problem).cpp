#include <bits/stdc++.h>
using namespace std;
char a;
long long powof10(long long x)
{
    long long res=1;
    for(long long i=1;i<=x;i++)
    {
        res=res*10;
    }
    return res;
}
int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    long long pos=1;
    for(;pos<=10;++pos)
    {
        cout << "? "<< powof10(pos) << "\n";
        fflush(stdout);
        cin >> a;
        if(a=='N')
        {
            pos--;
            break;
        }
    }
    if(pos==11)
    {
        for(long long i=1;i<=10;i++)
        {
            cout << "? " << powof10(i)-1 << "\n";
            fflush(stdout);
            cin >> a;
            if(a=='Y')
            {
                cout << "! " << powof10(i-1);
                return 0;
            }
        }
    }
        long long l=powof10(pos),r=powof10(pos+1)-1;
        while(l!=r)
        {
            long long mid=(l+r)/2;
            cout << "? " << mid*10 << "\n";
            fflush(stdin);
            cin >> a;
            if(a=='N')
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        cout << "! " << l;
        return 0;
}
