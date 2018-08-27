#include <bits/stdc++.h>
using namespace std;
int board1[6],board2[6];
int main()
{
    int n;
    cin >> n;
    for(int k=1;k<=4;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                char t;
                cin >> t;
                if((i+j)%2==0 && t=='1') board1[k]++;
                if((i+j)%2==1 && t=='0') board1[k]++;
                if((i+j)%2==0 && t=='0') board2[k]++;
                if((i+j)%2==1 && t=='1') board2[k]++;
            }
        }
    }
    int ans=999999;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            if(i==j) continue;
            int sum=board1[i]+board1[j];
            for(int k=1;k<=4;k++)
            {
                if(k!=i && k!=j)
                    sum+=board2[k];
            }
            ans=min(ans,sum);
        }
    }
    cout << ans << "\n";
}
