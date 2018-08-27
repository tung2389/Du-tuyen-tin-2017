#include <iostream>
#include <string.h>
#include <map>
using namespace std;

map<string,int> m;
int count = 1;
void change(string s,int n)
{
	if(s.size()==n)
	{
		m[s]=count++;
		return;
	}
	char last;
	if(s.size()==0)
	{
		last='a';
		}
		else
		{
			last=s[s.size()-1]+1;
			}
			for(char i=last;i<='z';i++)
			{
				change(s+i,n);
				}
				}
				int main()
				{
					string s;
					for(int i=1;i<=5;i++)
					{
						change("",i);
					}
					while(cin >> s)
					{
						cout << m[s] << "\n";
						}
						}
	
