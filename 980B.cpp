#include <bits/stdc++.h>
using namespace std;
int n,k;
char a[6][110];
int main()
{
	cin >> n >> k;
	if(k>(n-2)*2)
    {
        cout << "NO" << "\n";
        return 0;
    }
    cout << "YES" << "\n";
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]='.';
        }
    }
    int t=k;
    if(n%2==1)
    {
        if(k%2==1)
        {
            for(int i=2;i<=3;i++)
            {
                if(t<=1)
                    break;
                for(int j=2;j<=(k+1)/2;j++)
                {
                    if(t<=1)
                        break;
                    if(j>=(n+1)/2)
                        break;
                        a[i][j]='#';
                        a[i][n-j+1]='#';
                        t-=2;
                }
            }
        }
        else
        {
            if(t<=2)
            {
                for(int i=2;i<=3;i++)
                {
                    if(t<=0)
                        break;
                    a[i][(n+1)/2]='#';
                    t-=1;
                }
            }
            else
            {
            for(int i=2;i<=3;i++)
            {
                if(t<=0)
                    break;
                for(int j=2;j<(n+1)/2;j++)
                {
                    if(t<=0)
                        break;
                    a[i][j]='#';
                    a[i][n-j+1]='#';
                    t-=2;
                }
            }
        }
        }
    }
    else
    {
        if(k%2==1)
        {
            cout << "NO" << "\n";
            return 0;
        }
        else
        {
            for(int i=2;i<=3;i++)
            {
                if(t<=0)
                    break;
                for(int j=2;j<=n/2;j++)
                {
                    if(t<=0)
                        break;
                    a[i][j]='#';
                    a[i][n-j+1]='#';
                    t-=2;
                }
            }
        }
    }
    if(t>0)
    {
        for(int i=2;i<=3;i++)
                {
                    if(t<=0)
                        break;
                    a[i][(n+1)/2]='#';
                    t-=1;
                }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout << a[i][j];
        }
        cout << "\n";
    }
}
