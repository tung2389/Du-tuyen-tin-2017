#include <iostream>
#include <stdio.h>
using namespace std; 
#define mp make_pair

const int N = 2000005;
 
int n, a[N], w[N];
pair<int,int> q[N];
 
int main()
{
    freopen("debtsin.txt","r",stdin);
    freopen("debtsout.txt","w",stdout);
    int i,s, t;
    scanf("%d",&n);
    for(i = 1; i <= n; ++ i)
    {
        scanf("%d",&a[i]);
        a[i+n] = a[i];
    }
    for(int i = 1; i <= n*2; ++ i) w[i] = w[i-1] - a[i];
    s = 1; t = 0;
    for(i = 1; i <= n; ++ i)
    {
        while(s <= t && q[t].second >= w[i]) -- t;
        q[++ t] = mp(i, w[i]); 
    } 
    if(q[s].second >= 0) {printf("1"); return 0;}
    for(i = n + 1; i <= n * 2; ++ i)
    {
        while(s <= t && q[s].first <= i - n) ++ s;
        while(s <= t && q[t].second >= w[i]) -- t;
        q[++ t] = mp(i, w[i]); 
        if(q[s].second >= w[i-n]) break;
    } 
    printf("%d",i-n+1);
    return 0;
}
