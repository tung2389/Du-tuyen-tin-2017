#include <iostream>
using namespace std;
int n,a[100005],pos[100005];
int ans=0;
void set(int len)
{
	int MIN=n,MAX=0;
	for(int i=1;i<=len;i++)
	{
		if(pos[i]==0) break;
		MIN=min(MIN,pos[i]);
		MAX=max(MAX,pos[i]);
		if(MAX-MIN==i-1)
		ans=max(ans,i);
	}
}
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	cin >> a[i];
	n=n+1;
	a[n]=a[n-1];
	int l=1;
	for(int r=1;r<=n;r++)
	{
		if(pos[a[r]]>0)
		{
			if(ans<r-l) set(r-l);
			while(a[l]!=a[r])
			{
				pos[a[l]]=0;
				l++;
			}
			l=l+1;
		}
	    pos[a[r]]=r;
	    }
	    cout << ans;
}
	
		
