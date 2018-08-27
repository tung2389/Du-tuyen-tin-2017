#include <bits/stdc++.h>
using namespace std;
int x[200010],y[200010];
pair<int,int> pos[200010];
int main()
{
	freopen("CARDS.INP","r",stdin);
	freopen("CARDS.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int cnt=0;
	bool ok=false;
	pos[0].first=0;
	pos[n+1].first=2e8;
	for(int i=1;i<=n;i++)
	{
		cin >> x[i] >> y[i];
		if(x[i]==y[i])
		cnt++;
		if(x[i]<=y[i])
		{
			if(x[i]>=pos[i-1].first)
			pos[i].first=x[i];
			else
			pos[i].first=y[i];
		}
		else if(x[i]>=y[i])
		{
			if(y[i]>=pos[i-1].first)
			pos[i].first=y[i];
			else
			pos[i].first=x[i];
		}
		pos[i].second=i;
	}
	//for(int i=1;i<=n;i++)
	//{
	//	cout << pos[i].first << " ";
	//}
	x[n+1]=2e8;
	y[n+1]=2e8;
	x[0]=0;
	y[0]=0;
	if(cnt==n)
	ok=true;
	int q;
	cin >> q;
	for(int i=1;i<=q;i++)
	{
		int l,r;
		cin >> l >> r;
		if(ok==true)
		{
			swap(x[l],x[r]);
			for(int i=1;i<=n;i++)
			cout << x[i] << " ";
			cout << "\n";
			if(x[l]>x[l+1]||x[l]<x[l-1]||x[r]>x[r+1]||x[r]<x[r-1])
			cout << "RABBJT" << "\n";
			else
			{
				cout << "MAJIK" << "\n";
			}
		}
		else
		{
			//swap(x[l],x[r]);
			//swap(y[l],y[r]);
			ok=true;
			swap(pos[l],pos[r]);
			//cout << pos[l].first << " " << pos[l].second << "\n";
			//cout << pos[r].first << " " << pos[r].second << "\n";
			for(int j=1;j<=n;j++)
			{
				if(min(x[pos[j].second],y[pos[j].second])>=pos[j-1].first)
				{
					pos[j].first=min(x[pos[j].second],y[pos[j].second]);
				}
				else
				{
					pos[j].first=max(x[pos[j].second],y[pos[j].second]);
				}
				if(pos[j].first<pos[j-1].first)
				{
					cout << "RABBJT" << "\n";
					ok=false;
					break;
				}
			}
			if(ok==true)
			{
			cout << "MAJIK" << "\n";
			ok=false;
			}
		}
	}
}
