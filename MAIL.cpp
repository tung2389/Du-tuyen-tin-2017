#include<stdio.h>
#include<math.h>
int main () {
	//freopen("mail.inp","r",stdin);
	//9freopen("mail.out","w",stdout);
	int n,s[100000],maxleft=0,maxright=0,k,ans,a;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		k=s[i]-i;
		if(k>0&&k>maxright)
		maxright=k;
		else if(k<0&&k<maxleft)
		maxleft=k;
	}
	a=abs(maxleft);
	if(a>maxright)
	ans=maxright+maxright+a;
	else if(a<=maxright)
	ans=maxright+a+a;
	printf("%d",ans);
}
