#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
vector<ii> p;
int main()
{	
	freopen("postin.txt","r",stdin);
	freopen("postout.txt","w",stdout);
	int n;
	cin>>n;
	int a,b,i;
	for(i=1 ; i<=n ; i++)
	{
		cin>>a>>b;
		p.push_back(ii(a,a+b));
	}
	int str=0;
	for(i=1 ; i<n ; i++)
	{
	
			if(p[str].second>p[i].first)
			{
				str=i;
			}
	
	}
	cout<<str+1;
}
