#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int idem=0;
int A,B;
int root[10000];
struct Edge {
 
    int u, v, w;
    
    bool operator<(const Edge &p) const
    {
        return w < p.w;
    }
};
vector<Edge> e;
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
    if(x!=y)
    {
    	root[y]=x;
    	}
	
	
}
int krushkal(int n)
{
    
    sort(e.begin(), e.end());

   for(int i=0;i<n;i++)
   {
   	root[i]=i;
   }

    int  sum = 0;
    for(int i = 0; i < (int)e.size(); i++){
            idem++;
            if(root[B]==A)
            root[B]==-1;
            else
            sum += e[i].w;
            if(idem==n-1) break;
        }
         return sum;
    }
   

	int main()
	{
	//freopen("RUNNING.inp","r",stdin);
	//freopen("RUNNING.out","w",stdout);
		e.clear();
		int n;
		cin >> n >> A >> B;
		for(int i = 0; i <n-1; i++) {
            int u, v, w;
            cin>>u>>v>>w;
            Union(u,v);
            Edge data;
            data.u = u;
            data.v = v;
            data.w = w;
            e.push_back(data);
        }
        int res = krushkal(n);
        cout<<res;
        
      
        
        }
