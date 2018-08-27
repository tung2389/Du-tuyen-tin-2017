#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
/*
Source chung minh: https://books.google.com.vn/books?id=0UV5AgAAQBAJ&pg=SA3-PA9&lpg=SA3-PA9&dq=treelike+scheduling+pj/wj&source=bl&ots=027D4Q7VGs&sig=luKCm5gpa8wHP38Unx11VG-QN8o&hl=vi&sa=X&ved=0ahUKEwj9haDr0J3YAhWLx7wKHSTpDakQ6AEIJzAA#v=onepage&q=treelike%20scheduling%20pj%2Fwj&f=false
*/
int n,r;
int p[10001],W[10001],cost[10001],father[10001];
bool canuse[10001];
int main() {
	//freopen("1205.inp","r",stdin);
	//freopen("1205.out","w",stdout);
	while (cin>>n>>r) {
		if (!n&&!r) return 0;
		memset(canuse,true,sizeof(canuse));
		/*
		Tat ca thoi gian la 1s, theo nhu de bai ban dau.
		p[i] la gia de lam cong viec (to mau)
		cost[i] la gia de lam cong viec i va tat ca cac con cua no da duoc chon cho toi thoi diem 
		hien tai.
		*/
		for (int i=1;i<=n;i++) {
			W[i]=1;
			cin>>p[i];
			cost[i]=p[i]; 
		}
		/*
		father[i] giu bien cha cua node i trong cay, tuc bien phai duoc hoan thanh truoc khi lam i.
		*/
		for (int i = 1; i < n; i++) {
			int dad,child;
			cin>>dad>>child;
			father[child]=dad;
		}
		
		/*
		@param maxnode la node voi gia tri pj/Wj lon nhat ta se tim duoc trong cay
		
		Chay i=1 den n-1, boi vi ta se phai cap nhat n-1 node tong cong (tru node root).
		*/
		
		for (int i=1;i<n;i++) {
			float maxpW=-1;
			int maxnode=1;
			for (int j=1;j<=n;j++) {
				if (float(p[j])/float(W[j])>maxpW&&canuse[j]&&j!=r) {
					maxpW=float(p[j])/float(W[j]);
					maxnode=j;
				}
			}
			//Doan nay tim max pj/Wj trong ca cay, tim node max do.
			canuse[maxnode]=false;
			/*
			Gia su ta tim duoc 1 doan maxnode, nhung co father[maxnode] chua duoc to mau.
			Tu do, ta thay ta phai to mau maxnode ngay sau khi father cua no duoc to.
			Vi the, ta co the gop maxnode vao father cua no.
			*/
			//Khong cho phep dung node nay nua
			int dad=father[maxnode];
			for (int k=1;k<=n;k++) {
				if (father[k]==maxnode) father[k]=dad;
			}
			/*
			Vi chung ta se ket hop minnode voi cha cua no, tat ca cac con hien tai cua maxnode se co
			cha moi la father[maxnode], trong truong hop nay la dad.
			*/
			p[dad]=p[dad]+p[maxnode];
			//Ket hop 2 cong viec, gia moi la p[dad]+p[maxnode]
			cost[dad]=cost[dad]+W[dad]*p[maxnode]+cost[maxnode];
			/*
			Ta tuong tuong ta se lam cong viec maxnode vao thu tu thu k, so voi cha la i.
			Truoc do, ta se da lam k-1 cong viec khac, vay W[i]=k-1 (tinh ca i).
			Lam vao thu tu thu k=> thoi gian la p[maxnode]*k (DANG XET VOI i THOI)
			Ta lai thay, cost[maxnode] da bao gom ca 1 maxnode, cong voi (k-1)*maxnode con lai, ta nhan
			duoc k*p[maxnode].
			Gio ta tuong tuong ta lai lam cong viec i voi thu tu h so voi viec r.
			Ta se thay thu tu lam cong viec j so voi r se la h+k.
			Cach hoat dong:
			cost[i] da bao gom k lan maxnode.
			p[i] bao gom 1 lan maxnode.
			Vi lam cong viec i thu tu h, p[i] se nhan len h lan.
			Tu do ta se co h lan maxnode.
			cong voi k lan maxnode khi cong voi cost[i].
			Ta nhan duoc h+k lan maxnode.
			(Tao co mai giai thich duoc the nay thoi, thang nao ko hieu tu tuong tuong nhe)
			*/
			W[dad]=W[dad]+W[maxnode];
			//Ket hop 2 cong viec, thoi gian lam se la tong thoi gian can lam dad va maxnode
		}
		int ans=cost[r];
		//Sau n-1 buoc ket hop, ans cho bai tap se nam o root. In ra cost[r]
		cout<<ans<<"\n";
	}
}
