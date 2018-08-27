#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;
#define INF 1000000000

int root [1000];

void dijkstra(int s, vi *dist, vector<vii> *graph){
    priority_queue< ii, vector<ii>, greater<ii> > pq; 
    pq.push(ii(0, s));
    while (!pq.empty()) {
        ii front = pq.top(); 
        pq.pop();
        int d = front.first, u = front.second;
        if (d == dist->at(u))
            for (int j = 0; j < (int)graph->at(u).size(); j++) {
                ii v = graph->at(u)[j];                                     // all outgoing edges from u
                if (dist->at(u) + v.second < dist->at(v.first)) {
                    dist->at(v.first) = dist->at(u) + v.second;             // relax operation
                    root[v.first]=u;
                    pq.push(ii(dist->at(v.first), v.first));
                }
            } 
    }
}

void coutthegraph(int s, int t)
{
    if(s==t){printf("%d",t); return;}
    coutthegraph(root[s],t);
    printf(" %d",s);
}

int main(){
    int N,Case=1;
    while(scanf("%d",&N) && N){
        memset(root,-1,sizeof root);
        vector<vii> graph (N+1,vii());
        //Read graph
        for(int i = 1; i<=N;i++)
        {   
            int relations,v,w;
            scanf("%d",&relations);
            for (int j = 0; j < relations; ++j)
            {
                scanf("%d %d",&v,&w);
                graph[i].push_back(ii(v, w)); 
            }
        }

        int s,t;

        scanf("%d %d",&s,&t);
        vi dist(N+1, INF);
        dist[s] = 0;
        dijkstra(s,&dist,&graph);
       printf("Case++ %d: Path = ",Case++);
        coutthegraph(t,s);
        printf("; %d second delay\n",dist[t]);
 
    }


 return 0;   

}
