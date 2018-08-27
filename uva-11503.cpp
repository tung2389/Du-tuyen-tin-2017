#include <iostream>
#include <map>
using namespace std;

long long int facebook[100000],MAX=1;
long long int F;
string X,Y;
map<string,long long int> s;
long long int Friend[100000];
long long int find(long long int i)
{
	if(Friend[i]==i)
	return i;
	else
	return Friend[i]=find(Friend[i]);
}
void Union(long long int x,long long int y)
{
	x=find(x);
	y=find(y);
	if(x!=y)
	{
		facebook[x]+=facebook[y];
		Friend[y]=x;
	
	}
	cout<<facebook[x]<<"\n";
	
}
int main()
{
	long long int a;
	long long int N;
	cin >> N;
	while(N--)
	{
		a=0;
          s.clear();
	cin >> F;
	 for(long long int i=0;i<F;i++)
	 {
	 		cin >> X >> Y;
	  if(s.find(X)==s.end())
	  {
	  
          
        Friend[a]=a, facebook[a]=1;
        s[X]=a++;
    }
     if(s.find(Y)==s.end())
            {
                  Friend[a]=a, facebook[a]=1;
                s[Y]=a++;
            }
            long long int j=s[X];
long long int k=s[Y];
Union(j,k);
          
    }	
}
return 0;
}
