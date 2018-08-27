#include <iostream>
using namespace std;




int main(){
	freopen("frogin.txt","r",stdin);
	freopen("frogout.txt","w",stdout);
	int h[100000],n,dpl[100000],dpr[100000],MIN=0;
	cin >> n;
	for(int i=0; i<n; ++i) cin>>h[i];
	MIN = h[0];
	for(int l=0; l<n; ++l){
		if(h[l]<MIN) MIN=h[l];
		dpl[l]=MIN;
	}
	
	MIN = h[n-1];
	for(int r=n-1; r>=0; --r){
		if(h[r]<MIN) MIN=h[r];
		dpr[r]=MIN;
	}

	MIN=0;
	for(int m=1; m<n-1; ++m){
		if( h[m]>dpl[m-1] && h[m]>dpr[m+1] && h[m]-dpl[m-1] + h[m]-dpr[m+1] > MIN)
			MIN = h[m]-dpl[m-1] + h[m]-dpr[m+1];
	}

	cout<<MIN;
	
}
