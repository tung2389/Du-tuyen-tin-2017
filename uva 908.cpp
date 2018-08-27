#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int idem=0;
int connect[10000];
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
	if (connect[i]==i)
	return i;
	else
	return find(connect[i]);
}
int krushkal(int n)
{
    
    sort(e.begin(), e.end());

   for(int i=0;i<n;i++)
   {
   	connect[i]=i;
   }

    int count = 0, sum = 0;
    for(int i = 0; i < (int)e.size(); i++){
        int u = find(e[i].u);
        int v = find(e[i].v);
        if(u!=v)
        {
            connect[u] = v;
            idem++;
            if(root[B])
            sum += e[i].w;
            if(idem==n-1) break;
        }  
    }
    return sum;
}
int main()
{
	bool check=true;
	int n,A,B;
	
        cin>>n >> A >> B;
        for(int i = 0; i < n-1; i++) {
            int u, v, w;
            cin>>u>>v>>w;
            Edge data;
            data.u = u;
            data.v = v;
            data.w = w;
            e.push_back(data);
        }
        if(!check) printf("\n");
        check = false;
 
        int res = krushkal(n);
         cout << res;
    
    }
    
    

