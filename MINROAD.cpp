#include <bits/stdc++.h>
using namespace std;
#define ced first
#define bam second
int n,a,b,ansx,ansy,ans=2e9;
pair<int,int> p[300010],tree[300010];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cedrus=0,bamboo=0;
	cin >> n >> a >> b;
	for(int i=1;i<=n;i++)
	{
	cin >> p[i].first >> p[i].second;
    }
	sort(p+1,p+1+n);
	tree[0].ced=0;
	tree[0].bam=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i].second==1)
		tree[i].ced++;
		else if(p[i].second==2)
		tree[i].bam++;
		tree[i].ced+=tree[i-1].ced;
		tree[i].bam+=tree[i-1].bam;
	}
	  int l = 1;
    for (int i=1; i<=n; i++) {
        while (tree[i].ced-tree[l-1].ced>=a && tree[i].bam-tree[l-1].bam>=b) {
            ans = min(ans, p[i].first - p[l].first);
            l++;
        }
    }
	if(ans==2e9)
	cout << "-1";
	else
	cout << ans;
}	 
