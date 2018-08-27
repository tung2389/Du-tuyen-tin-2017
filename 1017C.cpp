#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int t=sqrt(n);
    if(t*t!=n)
    {
        t=t+1;
    }
    int cntt=t-1;
    int i=n;
    int pos=n;
    while(i--)
    {
        if(cntt<0)
        {
        cntt=t-1;
        pos=pos-t;
        if(pos<t)
        {
            for(int i=1;i<=pos;i++)
            {
                cout << i << " ";
            }
            return 0;
        }
        }
        cout << pos-cntt << " ";
        cntt--;
    }
}
