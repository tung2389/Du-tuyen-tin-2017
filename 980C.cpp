#include <bits/stdc++.h>
using namespace std;
int p[100010];
bool check[100010];
int group[100010];
int sizee[100010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> p[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(!check[p[i]])
        {
        bool ok=false;
        int pos=p[i]-(k-1);
        if(pos<0)
        {
            pos=0;
        }
        int anspos;
        for(int j=pos;j<=p[i];j++)
        {
            if(!check[j])
                {
                    anspos=j;
                    break;
                }
            else if(p[i]-group[j]+1<=k)
            {
                anspos=j;
                ok=true;
                break;
            }
        }
        for(int j=anspos;j<=p[i];j++)
        {
            group[j]=anspos;
            check[j]=1;
        }
        if(ok)
        {
            for(int j=group[anspos];j<=p[i];j++)
            {
                sizee[j]=p[i]-group[anspos]+1;
            }
        }
        //cout << anspos << "\n";
        //cout << pos << "\n";
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout << group[p[i]] << " ";
    }
}
