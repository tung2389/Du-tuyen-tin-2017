#include <iostream>
using namespace std;

int main()
{
	freopen("archin.txt","r",stdin);
	freopen("archout.txt","w",stdout);
	int n,a,b;
	cin >> n >> a >> b;
	if(a>b)
    swap(a,b);
    //thu hang cao nhat co the
	if(n-b>=a-1) // so thi sinh kem diem o thu hang thap nhat trong hai ngay >= so thi sinh hon diem o ngay co thu hang cao nhat,kha nang hay nhat la xep thu 1
	cout << "1" << " ";
	else
	cout << a-(n-b) << " ";//truong hop tren sai thi tinh huong tot nhat la thu hang cao nhat co the bang so nguoi hon diem thu hang cao nhat tru so nguoi kem diem thu hang thap nhat cong 1
	//thu hang thap nhat co the
	if(b-1>=n-a) // so thi sinh hon diem o thu hang thap nhat >= so thi sinh kem diem o thu hang cao nhat
	cout << n; // luc nay thu hang toi te nhat la n
	else 
	cout << b-1+a;//truong hop tren sai thi tinh huong xau nhat la b-1+a
}
