#include<iostream>
using namespace std;
long long n;
long long get(long long n){
    long long l = 0, r = 1e9, mid;
    while(l < r){
        mid = (l + r)/2;
        if(mid * (mid + 1) * 3 >= n) r = mid;
        else l = mid + 1;
    }
    return l;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long x=0,y=0;
    cin >> n;
    if(n == 0){
        cout << "0 0";
    }
    else
    {
    long long a = get(n);
    long long c = n - 3 * a * (a - 1);
    if(c <= a){
        x = a * 2 - c;
        y = c * 2;
    } 
    else if(c <= 2*a){
        c -= a;
        x = a - c * 2;
        y = a * 2;
    } 
    else if(c <= a * 3){
        c -= a * 2;
        x = -a - c;
        y = a * 2 - c * 2;
    } 
    else if(c <= a * 4){
        c -= a * 3;
        x = -a * 2 + c;
        y = -c * 2;
    }
    else if(c <= a * 5){
        c -= a * 4;
        x = -a + c * 2;
        y = -a * 2;
    } 
    else{
        c -= a * 5;
        x = a + c;
        y = -a * 2 + c * 2;
    }
    cout << x << " " << y;
}
}
