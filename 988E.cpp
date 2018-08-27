#include <bits/stdc++.h>
using namespace std;
long long ans=1e9;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    long long n=s.size();
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<n;j++)
        {
            if(i==j)
                continue;
            string t=s;
            long long tmp=0;
            for(long long k=i;k<n-1;k++)
            {
                swap(t[k],t[k+1]);
                tmp++;
            }
            for(long long k=j-(j>i);k<n-2;k++)
            {
                swap(t[k],t[k+1]);
                tmp++;
            }
            long long pos;
            for(long long k=0;k<n;k++)
            {
                if(t[k]!='0')
                {
                    pos=k;
                    break;
                }
            }
            for(long long k=pos;k>0;k--)
            {
                swap(t[k],t[k-1]);
                tmp++;
            }
            long long preans=atoll(t.c_str());
            if(preans%25==0)
            {
                ans=min(ans,tmp);
            }
        }
    }
    if(ans==1e9)
        cout  << "-1" << "\n";
    else
        cout << ans << "\n";
}
