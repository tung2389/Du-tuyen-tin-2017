#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int root[100000];
int idem=1;
int find(int i)
{
	if(root[i]==i)
	return i;
	else
	return root[i]=find(root[i]);
}


struct edge
{
	int u,v,w;

	};
	bool comp(const edge &s1, const edge &s2)
{
    return s1.w > s2.w;
}
vector <edge> e;
void krushkal(int n,int x,int y,int z)
{
 
	sort(e.begin(),e.end(),comp);
	for(int i=0;i<n;i++)
	{
		root[i]=i;
	}

	for(int i=0;i<(int)e.size();i++)
	{
		int u=find(e[i].u);
		int v=find(e[i].v);
		if(u!=v)
		{
		 
			root[v]=u;
		    x=find(x);
		    y=find(y);
		   
		    if(x==y)
		    {
		    	  cout << "Scenario #" 
                         << idem++
                         << endl
                         << "Minimum Number of Trips = "
                         << (z + e[i].w - 1) / e[i].w
                         << endl << endl;
                    break;
		}
		
		}
		}
		}
int main()
{
	int N,R;
	while(cin >> N >> R,N||R)
	{
		e.clear();
		for(int i=0;i<R;i++)
		{		
			int u,v,w;
			cin >> u >> v >> w;
			edge data;
			data.u=u;
			data.v=v;
			data.w=w;
			--data.w;
			e.push_back(data);
			}
			int S,D,T;
			cin >> S >> D >> T;
			krushkal(N,S,D,T);
			}
	
			}
