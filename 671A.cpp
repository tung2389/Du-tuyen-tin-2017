#include <bits/stdc++.h>
using namespace std;
double dist(double x1,double y1,double x2,double y2)
{
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
int main()
{
	double ax,ay,bx,by,tx,ty;
	cin >> ax >> ay >> bx >> by >> tx >> ty;
	double n;
	cin >> n;
	double sum=0;
	double mina=999999999999,minb=999999999999,minab=999999999999;
	for(int i=1;i<=n;i++)
	{
		double px,py;
		cin >> px >> py;
		sum+=2*dist(px,py,tx,ty);
		double pc=dist(px,py,tx,ty),pa=dist(ax,ay,px,py),pb=dist(bx,by,px,py);
		double pa2=pa-pc,pb2=pb-pc;
		minab=min(minab,min(mina+pb2,minb+pa2));
		mina=min(mina,pa2);
		minb=min(minb,pb2);
	}
	printf("%.12lf",sum+min(minab,min(mina,minb)));
}
