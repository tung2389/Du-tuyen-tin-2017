#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,x,y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    long long cnt=0;
    bool ok=true;
    if(s[0] == '0')
    {
    cnt++;
    ok=false;
    }
    for(long long i=1;i<n;i++)
    {
        if(s[i]=='0' && s[i-1] == '1')
        {
            cnt++;
        }
        if(s[i]== '0')
        ok=false;
    }
    if(ok)
    {
        cout << "0" << "\n";
    }
    else
    {
    if(x<y)
    {
        cout << (cnt-1) * x + y << "\n";
    }
    else
    {
        cout << cnt * y << "\n";
    }
    }
}
