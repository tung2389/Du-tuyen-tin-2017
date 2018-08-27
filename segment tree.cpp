
int t[100000];
void update(int id,int l,int r,int i,int v)
{
	if(i<l||i>r) return;
	if(l==r)
	{
		t[id]=v;
		return;
	}
	int mid=(r+l)/2;
	update(id*2,l,mid,i,v);
	update(id*2+1,mid+1,r,i,v);
}
long long get(int id,int l,int r,int i,int j)
{
	if(l>j||i>r) return 0LL;
	if(j>=l&&r>=i)
	{
		return t[id];
	}
	int mid=(r+l)/2;
	return max(get(id*2,l,mid,i,j),get(id*2+1,mid+1,r,i,j));
}
