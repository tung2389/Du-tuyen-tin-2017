#include <iostream>
using namespace std;

int main()
{
	
	int N,H,T[1000],count=0,MAX=0;
	cin >> N >> H;
	for(int i=0;i<N;i++)
	cin >> T[i];
	for(int i=0;i<N;i++)
	{
		if(T[i]>=H) 
		{
		count++;
		MAX=max(MAX,count);
		}
		else 
		{
		count=0;
		}
		}
		cout << MAX ;
		}
