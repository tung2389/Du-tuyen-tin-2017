#include <bits/stdc++.h>
using namespace std;

int pre[100010];
string pattern;
string text;
void precompute()
{
	int idx=0;
	int i=1;
	while(i<pattern.size())
	{
		if(pattern[i]==pattern[idx])
		{
			pre[i]=idx+1;
			idx++;
			i++;
		}
		else
		{
			if(idx!=0)
			{
				idx=pre[idx-1];
			}
			else
			{
				pre[idx]=0;
				i++;
			}
		}
	}
}
bool do_kmp()
{
	precompute();
	int i=0,j=0;
	while(i<text.size() && j<pattern.size())
	{
		if(text[i]==pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j!=0)
			{
				j=pre[j-1];
			}
			else
			{
				i++;
			}
		}
	}
	if(j==pattern.size())
	return true;
    return false;
}
int main()
{
	cin >> pattern;
	cin >> text;
	if(do_kmp())
	cout << "1" << "\n";
	else
	cout << "0" << "\n";
}
