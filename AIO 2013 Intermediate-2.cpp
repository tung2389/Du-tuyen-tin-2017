#include <iostream>
using namespace std;

int main()
{
	freopen("savein.txt","r",stdin);
	freopen("saveout.txt","w",stdout);
   int n,a[100000],ans,size[5],d;
	cin >> n;
	for(int i=0;i<=5;i++)
	{
		size[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		ans+=(a[i]/5)*5;
		size[a[i]%5]++;
	}
	d=min(size[3],size[4]);//min cua cac so du duoc lam tron len
	ans+=d*5;//cong vao phan lam tron len nho nhat,neu 3 va 4 thi lam tron len cung 5*d
	size[3]-=d;
	size[4]-=d;
	if(size[3]!=0)//neu size[3] van con thua
	{
		ans+=size[3]/2 * 5;//neu la du 3 thi nhan 2 se la cach co so tien it nhat,lam tron xuong 5
		size[3]=size[3]%2;// kiem tra xem size[3] het chua hay con thua
		if(size[3]!=0) ans+=5;//neu size[3] van con thua thi cong them 5
	}
	else if(size[4]!=0)//neu size[4] van con thua
	{
		ans+=size[4]/3 * 10;//size[4] nhan 3 thi lam tron xuong 10,cach tiet kiem nhat
		ans+=(size[4]%3)*5;//cong not phan thua cua size[4] se lam tron len 5
	}
    cout << ans;
}
