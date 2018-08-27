#include <bits/stdc++.h>
using namespace std;
int a[110],b[110];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,s;
    cin >> n >> s;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> b[i];
    }
    if(s+1<=a[1]*60+b[1])
    {
        cout << "0 0" << "\n";
        return 0;
    }
    for(int i=1;i<=n-1;i++)
    {
        if(a[i+1]*60+b[i+1]-a[i]*60-b[i]>=2*s+2)
        {
            int t=a[i]*60+b[i]+1+s;
            int h=t/60;
            int m=t-h*60;
            cout << h << " " << m << "\n";
            return 0;
        }
    }
    int t=a[n]*60+b[n]+1+s;
    int h=t/60;
    int m=t-h*60;
    cout << h << " " << m << "\n";
}
