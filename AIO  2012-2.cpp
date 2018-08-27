#include <bits/stdc++.h>
using namespace std;
 
const int N = 10000;
const int null = 1<<30;
 
int n, k;
int ans1, ans2;
int a1[N], a2[N];
stack<pair<int,int> >s;

int main()
{
    
    scanf("%d%d",&n, &k);
    int i, x;
    for(i = 1; i <= k; ++ i) 
    {
        scanf("%d",&x);
        a1[x] = i;
    }
    for(i = 1; i <= k + 1; ++ i)
    {
        scanf("%d",&x);
        a2[x] = i;
    }
    for(i = 1; i <= n; ++ i)
    {
        if(a2[i]) s.push(make_pair(i,a2[i]));
        if(a1[i] && s.size())
        {
            if(a1[i] == 1) ans1 = s.top().second;
            s.pop();
            a1[i] = 0;
        }
    }
    for(i = 1; i <= n; ++ i)
    {
        if(a1[i])
        {
            if(a1[i] == 1) ans1 = s.top().second;
            s.pop();
            a1[i] = 0;
        }
    }
    ans2 = s.top().second;
    printf("%d\n%d",ans1,ans2);
    return 0;
}
