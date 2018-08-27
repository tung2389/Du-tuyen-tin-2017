#include <bits/stdc++.h>
using namespace std;

int board[20][20];
#define unidentify 0
bool findvalid(int &row,int &col)
{
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(board[i][j]==unidentify)
            {
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}
bool SafeBox(int startrow,int startcol,int num)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[startrow+i][startcol+j]==num)
                return false;
        }
    }
    return true;
}
bool SafeRow(int row,int num)
{
    for(int i=1;i<=9;i++)
    {
        if(board[row][i]==num)
            return false;
    }
    return true;
}
bool SafeCol(int col,int num)
{
    for(int i=1;i<=9;i++)
    {
        if(board[i][col]==num)
            return false;
    }
    return true;
}
bool isSafe(int row,int col,int num)
{
    return (SafeRow(row,num) && SafeCol(col,num) && SafeBox(row-(row-1)%3,col-(col-1)%3,num));
}
bool backtrack()
{
    int row,col;
    if(!findvalid(row,col))
        return true;
    for(int num=1;num<=9;num++)
    {
        if(isSafe(row,col,num))
        {
            board[row][col]=num;
            if(backtrack())
                return true;
            board[row][col]=unidentify;
        }
    }
    return false;
}
int main()
{
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            cin >> board[i][j];
        }
    }
    cout << "\n";
    if(backtrack())
    {
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "There is no solution" << "\n";
    }
}
