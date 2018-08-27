#include <iostream>
using namespace std; 
int n, w, a[1000500], ans; 
 
int main()
{
    freopen("manin.txt","r",stdin);
    freopen("manout.txt","w",stdout);
    int i, s, e;
    scanf("%d%d",&n,&w);
    for(i = 1; i <= n; ++ i)
    {
        scanf("%d",&a[i]);
        a[i] += a[i-1];
    }
    for(i = 1; i+w-1 <= n; ++ i)
    {
        s = i; e = i + w - 1;
        if(a[e] - a[s-1] > ans)
            ans = a[e] - a[s-1];
    }
    printf("%d",ans);
    return 0;
}
