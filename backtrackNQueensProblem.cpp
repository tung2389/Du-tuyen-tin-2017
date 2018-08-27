#include <bits/stdc++.h>
using namespace std;
bool board[10][10];
int n;
void getans()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(board[j][i])
                cout << j << " ";
        }
    }
    cout << "\n";
}
bool isSafe(int x,int y)
{
    for(int i=1;i<=y;i++)
    {
        if(board[x][i])
            return false;
    }
    for(int i=x,j=y;i>=1 && j>=1;i--,j--)
    {
        if(board[i][j])
            return false;
    }
    for(int i=x,j=y;i<=n && j>=1;i++,j--)
    {
        if(board[i][j])
            return false;
    }
    return true;
}
bool solve(int y)
{
    if(y==n+1)
    {
        getans();
        return true;
    }
    bool res=false;
    for(int i=1;i<=n;i++)
    {
        if(isSafe(i,y))
        {
            board[i][y]=1;
            res=solve(y+1)||res;
            board[i][y]=0;
        }
    }
    return res;
}
int main()
{
    cin >> n;
    bool a=solve(1);
}
