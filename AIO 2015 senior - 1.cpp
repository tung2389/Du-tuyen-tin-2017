
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
 
const int N = 100005;
 
int n,c,k,s[N];
char str[N];
 
bool check(int x)
{
    int d,w;
    for(int i = 1; i + x - 1 <= n; i++)
    {
        d = i + x - 1;
        w = s[d] - s[i-1];
        if(x - w >= c || c - (x - w) <= k)
            return true; 
    }
    return false;
}
 
int main()
{
    freopen("chairsin.txt","r",stdin);
    freopen("chairsout.txt","w",stdout);
    int i,l,r,mid,ans;
    
    cin >> n >> c >> k;
    for(int i=1;i<=n;i++)
    cin >> str[i];
    
    for(i = 1; i <= n; ++ i)
        if(str[i] == 'w') s[i] = s[i-1] + 1;
        else s[i] = s[i-1];
    l = c; r = n;
    while(l <= r)
    {
        mid = (l + r)/2;
        if(check(mid)==true) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    printf("%d",ans);
    return 0;
}
