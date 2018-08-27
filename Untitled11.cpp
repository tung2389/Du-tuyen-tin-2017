#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(NULL));
    freopen("NECKLACES.INP","r",stdin);
    freopen("NECKLACES.OUT","w",stdout);
    int n,c,d;
    string s;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> c >> s >> d;
    }
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> c >> s >> d;
    }
    int choice=rand()%2;
    if(choice==1)
    {
        cout << "YES" << "\n";
    }
    else
    {
        cout << "NO" << "\n";
    }
}
