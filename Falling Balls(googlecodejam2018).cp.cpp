#include <bits/stdc++.h>
using namespace std;
int slashleft[100010],slashright[100010];
int a[100010];
char board[110][110];
int main()
{
    int t;
    cin >> t;
    int k=0;
    while(t--)
    {
        k++;
        int n;
        cin >> n;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            sum+=a[i];
        }
        cout << "Case #" << k << ": " ;
        if(a[1]<=0||a[n]<=0)
        {
            cout << "IMPOSSIBLE" << "\n";
            continue;
        }
        if(sum!=n)
        {
            cout << "IMPOSSIBLE" << "\n";
            continue;
        }
        for(int i=0;i<=100;i++)
        {
            for(int j=0;j<=100;j++)
            {
                board[i][j]='.';
            }
        }
        int ptr1=1,ptr2=1;
        int row=1;
        while(ptr1 <= n && ptr2 <=n)
        {
            if(a[ptr1]==1 && ptr1==ptr2)
            {
                ptr1++;
                ptr2++;
                continue;
            }
            if(a[ptr2]==0)
            {
                ptr2++;
                continue;
            }
            if(ptr1 < ptr2)
            {
                for(int i=ptr1;i<ptr2;i++)
                {
                    board[i-ptr1+1][i]='\\';
                }
                row=max(row,ptr2-ptr1+1);
                a[ptr2]--;
                if(a[ptr2]==0) ptr2++;
                ptr1++;
            }
            else
            {
                for(int i=ptr2+1;i<=ptr1;i++)
                {
                    board[ptr1-i+1][i]='/';
                }
                row=max(row,ptr1-ptr2+1);
                a[ptr2]--;
                if(a[ptr2]==0) ptr2++;
                ptr1++;
            }
        }
        cout << row <<  "\n";
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout << board[i][j];
            }
            cout << "\n";
        }
    }
}
