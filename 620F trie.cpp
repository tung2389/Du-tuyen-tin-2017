#include <iostream>
using namespace std;
int q,ans,now;
struct trie{
	int child[2],have[2];
} a[2000002*8];
void update(int x,int val)
{
	int p=0;
	for(int i=30;i>=0;i--)
	{
		int y=((x>>i)&1);
	    if(a[p].have[y]==0) a[p].child[y]= ++now;
	    a[p].have[y]+=val;
	    p=a[p].child[y];
	}
}
int getmax(int x)
{
	int p=0,res=0;
	for(int i=30;i>=0;i--)
	{
		int y=((x>>i)&1);
		if(y==0)
		{
			if(a[p].have[1])
			{
				p=a[p].child[1];
				res^=(1<<i);
			}
			else p=a[p].child[0];
		}
		else 
		{
			if(a[p].have[0]>0)
			{
				p=a[p].child[0];
			}
			else if(a[p].have[1]>0)
			{
				p=a[p].have[1];
				res^=(1<<i);
			}
		}
		}
		return res;
		}
		int main()
		{
			cin >> q;
			update(0,1);
			while(q--)
			{
				char type;
				int num;
				cin >> type >> num;
				if(type=='+') update(num,1);
				if(type=='-') update(num,-1);
				if(type=='?') cout << (getmax(num)^num) << "\n";
			}
		}
		
			
				
		
