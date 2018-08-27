#include <iostream>
#include <map>
using namespace std;
int nature[10000],MAX=1;
int C,R;
string X,Y;
map<string,int> s;
int animal[10000];
int find(int i)
{
	if(animal[i]==i)
	return i;
	else
	return animal[i]=find(animal[i]);
}
void Union(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x!=y)
	{
		nature[x]+=nature[y];
		animal[y]=x;
		MAX=max(nature[x],MAX);
	}
	
}
int main()
{


 
	while(1)
	{
	cin >> C >> R;
	if(C==0 && R==0)
	break;
	 for(int i=0;i<C;i++)
	 {
	 
        animal[i]=i, nature[i]=1;
        MAX=1;
    }
	for(int i=0;i<C;i++)
	{
		cin >> X;
		s[X]=i;
	}
	for(int i=0;i<R;i++)
	{
		cin >> X >> Y;
		Union(s[X],s[Y]);
	}
	cout << MAX<< "\n";
}
return 0;
}
