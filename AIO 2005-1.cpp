#include <iostream>
#include <queue>
using namespace std;

struct food
{
    int id, eat;
    food(){}
    food(int _, int __){id = _; eat = __;}
    friend bool operator< (food a, food b)
    {
        return a.eat < b.eat;
    }
};
	priority_queue<food> q;
int c,r,v,ans[4];
food x,y;
int main()
{
	freopen("curryin.txt","r",stdin);
	freopen("curryout.txt","w",stdout);
	cin >> c >> r >> v;
	q.push(food(1,c));
	q.push(food(2,r));
	q.push(food(3,v));
	while(1)
	{
		x=q.top();q.pop();
		y=q.top();q.pop();
		if(y.eat==0) break;
		x.eat--;y.eat--;
		q.push(x);q.push(y);
	if((x.id == 2 && y.id == 3)||(x.id == 3 && y.id == 2)) ++ ans[1];
        else if((x.id == 2 && y.id == 1)||(x.id == 1 && y.id == 2)) ++ ans[3];
        else ++ ans[2];
	}
 cout << ans[1] << ' ' << ans[2] << ' ' << ans[3];
	return 0;
	}
