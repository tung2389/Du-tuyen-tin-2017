#include <bits/stdc++.h>
using namespace std;
set<int> st;
void primefactor(int x)
{
	if(!(x&1))
	st.insert(2);
	while(!(x&1))
	x=x/2;
	for(int i=3;i<=sqrt(x);i+=2)
	{
		while(x%i==0)
		{
			st.insert(i);
			x=x/i;
		}
	}
	if(x>2)
	st.insert(x);
}
int main()
{
	primefactor(591722065);
	for(set<int>:: iterator it = st.begin(); it != st.end(); it++)
	{
		cout << *it << " ";
	}
}
