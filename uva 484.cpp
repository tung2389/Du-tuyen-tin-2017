#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){

	vector< int > V;
	map<int, int> Map;
	map<int, int>::iterator pointer;
	int I, i, j;
	while (cin >> I){
		pointer = Map.find(I);
		if (pointer != Map.end())
			++Map[I];
		else{
			Map[I] = 1;
			V.push_back(I);
		}
	}
	for(int i=0;i<V.size();i++)
		cout << V[i] << " " << Map[V[i]] << endl;
	return 0;
}
