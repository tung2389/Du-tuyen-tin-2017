#include <bits/stdc++.h>
using namespace std;
#define ii pair<long long,long long>
long long r,c;
stack<long long> st;
vector<pair<long long,long long> > ans;
long long change(long long x,long long y)
{
	if(y==0)
	{
		return x;
	}
	else if(x==r)
	{
	return r+y;
	}
	else if(y==c)
	{
		return r+c+(r-x);
	}
	return 2*r+c+(c-y);
}
int main()
{
	long long n;
	cin >> r >> c >> n;
	for(long long i=1;i<=n;i++)
	{
		long long x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1!=0 && y1!=0 && x1!=r && y1!=c)
		continue;
		if(x2!=0 && y2!=0 && x2!=r && y2!=c)
		continue;
		ans.push_back(ii(change(x1,y1),i));
		ans.push_back(ii(change(x2,y2),i));
	}
	sort(ans.begin(),ans.end());
	for(long long i=0;i<ans.size();i++)
	{
		if(!st.empty())
		{
			if(st.top()==ans[i].second)
			st.pop();
			else
			st.push(ans[i].second);
		}
		else
		{
			st.push(ans[i].second);
		}
	}
	if(st.empty())
	cout << "YES" << "\n";
	else
	cout << "NO" << "\n";
}
