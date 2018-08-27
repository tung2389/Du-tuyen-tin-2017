#include <iostream>
using namespace std;

int main()
{
	int x=13;
	x-=x&(-x);
	int t=x;
	cout << t;
}
