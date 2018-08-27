#include <bits/stdc++.h>
using namespace std;
long long board[600][600];
long long sum=0;
long long row;
int main()
{
    long long n;
    cin >> n;
    if(n==1)
        cout << "1" << "\n";
    else
    {
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=n;j++)
        {
            cin >> board[i][j];
            if(board[i][j]==0)
            {
                row=i;
            }
        }
    }
    if(row==1)
    {
        for(long long i=1;i<=n;i++)
        {
            sum+=board[2][i];
        }
    }
    else
    {
        for(long long i=1;i<=n;i++)
        {
            sum+=board[1][i];
        }
    }
    //cout << row << "\n";
    long long ans;
    for(long long j=1;j<=n;j++)
    {
        sum-=board[row][j];
    }
    ans=sum;
    for(long long j=1;j<=n;j++)
    {
        if(board[row][j]==0)
        {
            board[row][j]=ans;
        }
    }
    long long sum1=0,sum2=0;
    for(long long i=1;i<=n;i++)
    {
        sum1+=board[1][i];
        sum2+=board[i][1];
    }
    for(long long i=1;i<=n;i++)
    {
        long long sum=0;
        for(long long j=1;j<=n;j++)
        {
            sum+=board[i][j];
        }
        if(sum!=sum1)
        {
            cout << "-1" << "\n";
            return 0;
        }
    }
    for(long long i=1;i<=n;i++)
    {
        long long sum=0;
        for(long long j=1;j<=n;j++)
        {
            sum+=board[j][i];
        }
        if(sum!=sum2)
        {
            cout << "-1" << "\n";
            return 0;
        }
    }
    long long i=1,j=1;
    sum=0;
    while(i<=n && j<=n)
    {
        sum+=board[i][j];
        i++;
        j++;
    }
    if(sum!=sum1)
    {
        cout << "-1" << "\n";
        return 0;
    }
    //cout << sum << "\n";
    sum=0;
    i=1;j=n;
    while(i<=n && j>=1)
    {
        sum+=board[i][j];
        i++;
        j--;
    }
    if(sum!=sum1)
    {
        cout << "-1" << "\n";
        return 0;
    }
    //cout << sum << "\n";
    if(ans<=0)
        cout << "-1" << "\n";
    else
    cout << ans << "\n";
}
}
