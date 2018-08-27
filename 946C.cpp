#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int check=0;
	int z=97;
	int count=0;
	int i=0;
	while(s[i]!=0&&z<=122) 
	{
		if(s[i]<=z)
		s[i]=z++;
		i++;
	}
	if(z-123==0)
	cout << s;
	else
	cout << "-1";
}
