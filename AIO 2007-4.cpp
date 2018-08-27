
#include <bits/stdc++.h>
using namespace std;
 
const int N = 1005;
 
int n, a[N], f[N][N], ans;
 
int find(int L,int R,int x)
{
    int mid, ret = 0;
    while(L <= R)
    {
        mid = (L + R)/2;
        if(a[mid] >= x) ret = mid, R = mid - 1;
        else L = mid + 1;
    }
    return ret;
}
 
int main()
{
    freopen("dropin.txt","r",stdin);
    freopen("dropout.txt","w",stdout);
    int i, j, k;
    scanf("%d",&n);
    for(i = 1; i <= n; ++ i) scanf("%d",&a[i]);
    ans = 1;
    for(i = 2; i <= n; ++ i)
        for(j = i-1; j ; -- j)
        {
            f[i][j] = 2;
            k = find(1,j-1,2*a[j]-a[i]);
            if(k && a[j]-a[k] == a[i]-a[j]) 
                f[i][j] = max(f[i][j], f[j][k] + 1);
            ans = max(ans,f[i][j]);
        }
    printf("%d",ans);
    return 0;
}
