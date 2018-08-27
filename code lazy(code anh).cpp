#include <stdio.h>
#include <algorithm>
using namespace std;
long long n,a[100007],lazy[400007],k[400007],q;
void init(int i,int l,int r){
    if(l==r){
        k[i]=a[l];
        return;
    }
    int mid=(l+r)/2;
    init(i*2,l,mid);
    init(i*2+1,mid+1,r);
    k[i]=k[i*2]+k[i*2+1];
    return;
}
void lz(int i,int l,int r){
    if(lazy[i]==0) return;
    k[i]+=lazy[i]*(r-l+1);
    if(l!=r){
        lazy[i*2]+=lazy[i];
        lazy[i*2+1]+=lazy[i];
    }
    lazy[i]=0;
}
void upd(int i,int l,int r,int left,int right,long long val){
    lz(i,l,r);
    if(l>right || r<left || l>r) return;
    if(l>=left && r<=right){
        k[i]+=val*(r-l+1);
        if(l!=r){
            lazy[i*2]+=val;
            lazy[i*2+1]+=val;
        }
        return;
    }
    int mid=(l+r)/2;
    upd(i*2,l,mid,left,right,val);
    upd(i*2+1,mid+1,r,left,right,val);
    k[i]=k[i*2]+k[i*2+1];
}
long long get(int i,int l,int r,int left,int right){
    lz(i,l,r);
    if(l>right || r<left || l>r) return 0;
    if(l>=left && r<=right) return k[i];
    int mid=(l+r)/2;
    return (get(i*2,l,mid,left,right)+get(i*2+1,mid+1,r,left,right));
}
int main(){
    scanf("%I64d %I64d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
    }
    init(1,1,n);
    for(int i=1;i<=q;i++){
        int type,left,right;
        long long value;
        scanf("%d %d %d",&type,&left,&right);
        if(type==1){
            scanf("%I64d",&value);
            upd(1,1,n,left,right,value);
        }
        else{
            printf("%I64d\n",get(1,1,n,left,right));
        }
    }
}
