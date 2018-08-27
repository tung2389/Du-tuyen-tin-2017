#include <bits/stdc++.h>
using namespace std;
#define ii make_pair
vector<pair<int,int> > ans;
int cnt=0;
int main()
{
    int n,m;
    cin >> n >> m;
    if(m<n-1)
    {
        cout << "Impossible" << "\n";
        return 0;
    }
    for(int i=1;i<=n-1;i++)
    {
        if(cnt==m)
            break;
        for(int j=i+1;j<=n;j++)
        {
            if(cnt==m)
                break;
            if(__gcd(i,j)==1)
            {
                ans.push_back(ii(i,j));
                cnt++;
            }
        }
    }
    if(cnt!=m)
    {
        cout << "Impossible" << "\n";
    }
    else
    {
        cout << "Possible" << "\n";
        for(int i=0;i<ans.size();i++)
        {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
    }
}
