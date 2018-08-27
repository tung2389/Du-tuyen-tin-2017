#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector <int> v={10,20,20,31,90};
	vector<int>::iterator low,up;
	low=lower_bound(v.begin(), v.end(), 30);
	cout << low-v.begin();
}
