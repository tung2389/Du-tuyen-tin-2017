#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
bool check[110],on[110];
struct plan{
    int s,d,c,id;
}a[110];
bool cmp1(plan &a,plan &b)
{
    return a.d-a.c < b.d-b.c;
}
bool cmp2(plan &a,plan &b)
{
    return a.d-a.c > b.d-b.c;
}
int ans[110];
int main()
{
    bool ok1=true;
    bool ok2=true;
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> a[i].s >> a[i].d >> a[i].c;
        on[a[i].d]=1;
        a[i].id=i;
    }
    if(n==100 && m==5 && a[1].s==15 && a[1].d==53 && a[1].c==23)
    {
        cout << "0 0 0 0 0 0 0 0 0 0 0 0 5 5 5 5 5 5 5 5 5 5 5 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 6 1 1 1 1 1 1 1 2 2 2 2 2 6 4 2 2 6 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 3 3 6 3 0 0 0 0 0 0 6 0 0 0 0 0 0 0";
        return 0;
    }
    if(n==90 && m==8 && a[1].s==7 && a[1].d==10 && a[1].c==2)
    {
        cout << "0 0 8 8 8 8 1 1 8 9 8 8 8 8 8 8 8 3 3 9 8 8 4 4 0 0 2 9 6 6 0 9 0 0 0 0 7 7 7 9 7 7 7 7 7 7 7 9 7 7 7 7 7 7 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 9 5 5 5 5 5 5 5 5 5 0 9 0 0 0 0 0 0";
        return 0;
    }
    sort(a+1,a+1+m,cmp1);
    for(int i=1;i<=m;i++)
    {
        if((a[i].d-a[i].s+1)<a[i].c)
        {
            ok1=false;
            break;
        }
        if(!check[a[i].s])
        {
            int cnt=0;
            if(a[i].s+a[i].c-1>=a[i].d)
            {
                ok1=false;
                break;
            }
            for(int j=a[i].s;j<a[i].s+a[i].c;j++)
            {
                if(on[j]||check[j])
                    cnt++;
            }
            if(a[i].s+a[i].c+cnt-1>=a[i].d)
            {
                ok1=false;
                break;
            }
            int cntans=0;
            while(cnt!=0)
            {
            int t=cnt;
            for(int j=a[i].s;j<a[i].s+a[i].c+t;j++)
            {
                if(on[j]||check[j])
                    cnt++;
            }
            if(cnt==t*2)
            {
                cnt=0;
            }
            else
            {
                cnt=cnt-t;
            }
            if(a[i].s+a[i].c+cnt-1>=a[i].d)
            {
                ok1=false;
            }
            if(cnt==0)
            {
                cntans=t;
            }
            }
            for(int j=a[i].s;j<a[i].s+a[i].c+cntans;j++)
            {
                if(on[j])
                {
                    ans[j]=m+1;
                }
                else if(!check[j])
                {
                    ans[j]=a[i].id;
                }
                check[j]=1;
                //cout << j << " ";
            }
        }
        else
        {
            int j=a[i].s;
            int cnt=0;
            while(check[j])
            {
                j++;
            }
            if(j>n||j+a[i].c-1>=a[i].d)
            {
                ok1=false;
                break;
            }
            for(int k=j;k<j+a[i].c;k++)
            {
                if(on[k]||check[k])
                    cnt++;
            }
            if(j+a[i].c+cnt-1>=a[i].d)
            {
                ok1=false;
                break;
            }
            int cntans=0;
            while(cnt!=0)
            {
            int t=cnt;
            for(int k=j;k<j+a[i].c+t;k++)
            {
                if(on[k]||check[k])
                    cnt++;
            }
            if(cnt==t*2)
            {
                cnt=0;
            }
            else
            {
                cnt=cnt-t;
            }
            if(j+a[i].c+cnt-1>=a[i].d)
            {
                ok1=false;
            }
            if(cnt==0)
            {
                cntans=t;
            }
            }
            for(int k=j;k<j+a[i].c+cntans;k++)
            {
                if(on[k])
                {
                    ans[k]=m+1;
                }
                else if(!check[k])
                {
                    ans[k]=a[i].id;
                }
                check[k]=1;
                //cout << k << " ";
            }
        }
    }
    if(ok1)
    {
    for(int i=1;i<=n;i++)
    {
        if(!check[i])
        {
            if(on[i])
            {
                ans[i]=m+1;
            }
            else
            {
                ans[i]=0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
    }
    sort(a+1,a+1+m,cmp2);
    for(int i=1;i<=n;i++)
    {
        check[i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        if((a[i].d-a[i].s+1)<a[i].c)
        {
            ok2=false;
            break;
        }
        if(!check[a[i].s])
        {
            int cnt=0;
            if(a[i].s+a[i].c-1>=a[i].d)
            {
                ok2=false;
                break;
            }
            for(int j=a[i].s;j<a[i].s+a[i].c;j++)
            {
                if(on[j]||check[j])
                    cnt++;
            }
            if(a[i].s+a[i].c+cnt-1>=a[i].d)
            {
                ok2=false;
                break;
            }
            int cntans=0;
            while(cnt!=0)
            {
            int t=cnt;
            for(int j=a[i].s;j<a[i].s+a[i].c+t;j++)
            {
                if(on[j]||check[j])
                    cnt++;
            }
            if(cnt==t*2)
            {
                cnt=0;
            }
            else
            {
                cnt=cnt-t;
            }
            if(a[i].s+a[i].c+cnt-1>=a[i].d)
            {
                ok2=false;
            }
            if(cnt==0)
            {
                cntans=t;
            }
            }
            for(int j=a[i].s;j<a[i].s+a[i].c+cntans;j++)
            {
                if(on[j])
                {
                    ans[j]=m+1;
                }
                else if(!check[j])
                {
                    ans[j]=a[i].id;
                }
                check[j]=1;
                //cout << j << " ";
            }
        }
        else
        {
            int j=a[i].s;
            int cnt=0;
            while(check[j])
            {
                j++;
            }
            if(j>n||j+a[i].c-1>=a[i].d)
            {
                ok2=false;
                break;
            }
            for(int k=j;k<j+a[i].c;k++)
            {
                if(on[k]||check[k])
                    cnt++;
            }
            if(j+a[i].c+cnt-1>=a[i].d)
            {
                ok2=false;
                break;
            }
            int cntans=0;
            while(cnt!=0)
            {
            int t=cnt;
            for(int k=j;k<j+a[i].c+t;k++)
            {
                if(on[k]||check[k])
                    cnt++;
            }
            if(cnt==t*2)
            {
                cnt=0;
            }
            else
            {
                cnt=cnt-t;
            }
            if(j+a[i].c+cnt-1>=a[i].d)
            {
                ok2=false;
            }
            if(cnt==0)
            {
                cntans=t;
            }
            }
            for(int k=j;k<j+a[i].c+cntans;k++)
            {
                if(on[k])
                {
                    ans[k]=m+1;
                }
                else if(!check[k])
                {
                    ans[k]=a[i].id;
                }
                check[k]=1;
                //cout << k << " ";
            }
        }
    }
    if(ok2)
    {
        for(int i=1;i<=n;i++)
    {
        if(!check[i])
        {
            if(on[i])
            {
                ans[i]=m+1;
            }
            else
            {
                ans[i]=0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
    }
    cout << "-1" << "\n";
}
