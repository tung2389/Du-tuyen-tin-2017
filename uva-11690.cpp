#include <iostream>
using namespace std;

int people[10000],money[10000];
int find(int i)
{
	if(people[i]==i)
	return i;
    else
    return people[i]=find(people[i]);
}
void Union(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x!=y)
	{
		money[x]+=money[y];
		money[y]=0;
		people[y]=x;
	}
}

int main()
{
int N;
cin >> N;
while(N--)
{
	int n,m,x,y,cash;
	cin >> n >> m;
    for(int i=0;i<n;i++)
    {
	people[i]=i;
    cin >> cash;
    money[i]=cash;
}
for(int i=0;i<m;i++)
{
cin >> x >> y;
Union(x,y);
}
int i;
for(i=0;i<n;i++)
{
	if(money[i]!=0)
	{
	
	cout << "IMPOSSIBLE" << "\n";
	break;
}
	
}
if(i>n-1)
cout << "POSSIBLE" << "\n";
	
}
return 0;
}
