#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        while(a[i] != i)
        {
            swap(a[i],a[a[i]]);
            cnt++;
        }
    }
    if(n%2==0)
    {
        if(cnt%2==0)
        {
            cout << "Petr" << "\n";
        }
        else
        {
            cout << "Um_nik" << "\n";
        }
    }
    else
    {
        if(cnt%2==1)
        {
            cout << "Petr" << "\n";
        }
        else
        {
            cout << "Um_nik" << "\n";
        }
    }
}
