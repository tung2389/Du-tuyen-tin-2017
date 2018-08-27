#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
vector<pair<int,ii>  > adjlist;
int root[10000];
string s[1000];

int Dist(const string& first,const string& second)
{
	int dist=0;
    for(int i=0;i<4;i++)
    {
    	int MIN=min(first[i],second[i]);
    	int MAX=max(first[i],second[i]);
    	dist+=min(MAX-MIN,MIN+10-MAX);
    	}
    	return dist;
    	}
int find(int i)
{
	if(root[i]==i)
	return i;
	else
	return root[i]=find(root[i]);
}
void Union(int x,int y)
{
	x=find(x);
	y=find(y);
	root[x]=y;
}
int main()
{
	int num;
	cin >> num;
	while(num--)
	{
	
			adjlist.clear();
			int n;
			cin >> n;
				for(int i=0;i<n;i++)
		{
			root[i]=i;
			}
			for(int i=0;i<n;i++)
			{
				cin >> s[i];
				}
				for(int i=0;i<n;i++)
				for(int j=0;j<i;j++)
				{
					adjlist.push_back(make_pair(Dist(s[i],s[j]),make_pair(i,j)));//luu tru khoang cach giua cac nut va so hieu i,j vao adjlist
				}
				sort(adjlist.begin(),adjlist.end());
				int i=0;
				int T=0;
			    int edge=0;
			    while(edge<n-1)
			    {
			    	pair<int,ii> temp=adjlist[i];
			    	int u=temp.second.first;// là i
			    	int v=temp.second.second;//là j
			    	if(find(u)!=find(v))
			    	{
			    		Union(u,v);
			    		T+=temp.first;
			    		edge++;
			    		}
			    		i++;
			    		}
			    		int MIN=1000000;
			    		for(int j=0;j<n;j++)
			    		{
			    		    MIN=min(MIN,Dist("0000",s[j]));
			    		    }
			    		cout << T + MIN << "\n";
			    		}
			    		}
				
