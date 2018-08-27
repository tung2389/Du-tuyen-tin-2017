#include <bits/stdc++.h>
using namespace std;

#define a first
#define b second
#define pb push_back
#define mp make_pair
#define int long long
const int N = 1e5 + 5;
const int M = 1e6 + 5;
const int mod = 1e9 + 7;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
int a[N] , b[N], dp[N] , n;
vii v;
bool bad(ii l1,ii l2,ii l3)
{
    return log2(abs(l2.a - l1.a)) + log2(abs(l3.b - l1.b)) < log2(abs((l1.b - l2.b))) + log2(abs(l1.a - l3.a));
}
void add(int x,int y)
{
    ii s;
    s.a=x;
    s.b=y;
    while(v.size() > 1 && bad(v[v.size()-2],v[v.size()-1],s))
        v.pop_back();
    v.push_back(s);
}
int f(int pos,int x)
{
    return v[pos].a * x + v[pos].b;
}
int query(int x)
{
    int l=0,r=v.size()-1;
    while(l-r>2)
    {
        int m1=(l+l+r)/3,m2=(l+r+r)/3;
        if(f(m1,x) == f(m2,x)) l=m1,r=m2;
        else if(f(m1,x) > f(m2,x)) l=m1;
        else r = m2;
    }
    int ans = 9e18 + 2277;
    for(int i=l;i<=r;i++)
    {
        ans=min(ans,f(i,x));
    }
    return ans;
}
signed main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> b[i];
    }
    dp[1]=0;
    v.push_back({b[1],dp[1]});
    for(int i=2;i<=n;i++)
    {
        dp[i]=query(a[i]);
        add(b[i],dp[i]);
    }
    cout << dp[n] << "\n";
}
