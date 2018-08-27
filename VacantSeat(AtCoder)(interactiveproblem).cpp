#include <bits/stdc++.h>
using namespace std;
bool queries[100010];
string s,c;
int main()
{
	int n;
	cin >> n;
	cout << "0" << "\n";
	cout.flush();
	cin >> s;
	if(s=="Vacant")
    {
        return 0;
    }
    else
    {
        int l=1,r=n-1;
        while(l<r)
        {
            int mid=((l+r)>>1);
            cout << mid << "\n";
            cout.flush();
            cin >> c;
            if(c=="Vacant")
                return 0;
            string ans;
            if(mid%2==0)
            {
                ans=s;
            }
            else
            {
                if(s=="Female")
                    ans="Male";
                else
                    ans="Female";
            }
            if(c==ans)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        cout << l << "\n";
        cout.flush();
    }
}
