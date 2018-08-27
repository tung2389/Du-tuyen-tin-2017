#include <iostream>
using namespace std;
int count=0,s;
void backtrack(int pos,int sum)
{
	if(pos==s)
	{
		if(sum==0) count++;
		return;
	}
	if(sum-s-pos+1<=0) backtrack(pos+1,sum+1);
	if(sum>0) backtrack(pos+1,sum-1);
}
int main()
{
	cin >> s;
	backtrack(0,0);
	cout << count;
}
