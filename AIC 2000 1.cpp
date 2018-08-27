#include <iostream>
using namespace std;

int main()
{
	freopen("acadin.txt","r",stdin);
	freopen("acadout.txt","w",stdout);
	char c;
	int count1=0,count2=0;
	while(cin >> c && c!='x')
	{
		if(c=='i') count1++;
		if(c=='o') count2++;
	}
	if(count1>count2) cout << count1-count2;
	else
	cout << 0;
	}
