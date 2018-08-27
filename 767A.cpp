#include <bits/stdc++.h>
using namespace std;
int a[100010];
bool check[100010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int cur=n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        check[x]=1;
        if(x==cur)
        {
            int t;
            for(int i=cur;i>=1;i--)
            {
                if(check[i])
                {
                    t=i;
                    cout << i << " ";
                }
                else
                {
                    cur=t-1;
                    break;
                }
            }
            cout << "\n";
        }
        else
            cout << "\n";
    }
}
