#include <bits/stdc++.h>
using namespace std;
string s[2010];
int cnt[2010][2010];
int main()
{
    memset(cnt,0,sizeof(cnt));
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> s[i];
        s[i]="*"+s[i];
        for(int j=1; j<=m; j++)
        {
            if(s[i][j]=='1')
            {
                cnt[i][j]=cnt[i-1][j]+1;
            }
            else
            {
                cnt[i][j]=cnt[i-1][j];
            }
        }
    }
    /*for(int i=1;i<=m;i++)
    {
        cout << cnt[n][i] << " ";
    }*/
    for(int i=1; i<=n; i++)
    {
        bool ok=true;
        for(int j=1; j<=m; j++)
        {
            if((cnt[n][j]-(s[i][j] == '1'?1:0))<=0)
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            cout << "YES" << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";
}
