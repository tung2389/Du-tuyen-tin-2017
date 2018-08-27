#include<iostream>
using namespace std;
long long a[100000],n,sum=0,sum2=0,MAX=0,i=0,count=0,str=0,op=0;
bool check;
void dfs(long long k)
{
           sum=0;
			sum2=0;
			op=k;
			while(a[k]<=0 && k<n)
			{
				sum=sum-a[k];
				k++;
			}
			while(a[k]>=0 && k<n)
			{
				sum2=sum2+a[k];
				k++;
			}
			int m=sum-sum2;
			if(k==n-1)
			{
				str=op;
				check=true;
				return;
			}
			if(m<0)
			return;
			dfs(k+1);
}
int main()
{

	check=false;
	cin >> n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
    long long t=0;
	while(t<n)
	{
	    a[n+t]=a[t];
		t++;
	}
		long long c=0;

	while(c<2*n)
	{	
	       if(check==true)
	       break;
	       count++;	
		   dfs(c);
		   c=count;
	}
	cout<< str+1;
}
