#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("PASSPORT.INP","r",stdin);
	freopen("PASSPORT.OUT","w",stdout);
	int th,tm,starth[1000],startm[1000],endh[1000],endm[1000],process[1000],time=0,n;
	char a,c;
	cin >> th >> c >> tm;
	int t=th*60+tm;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> starth[i] >> c >> startm[i] >> endh[i] >> a >> endm[i] >> process[i];
		int start=starth[i]*60+startm[i];
		int end=endh[i]*60+endm[i];
		t=max(t,start);
		t=t+process[i];
		if(t>end)
		{
			cout << "No";
			return 0;
		}
	}
	int ansh=t/60;
	int ansm=t%60;
	cout << "Yes" << "\n";
	if(ansh<10)
	{
	if(ansm<10)
	{
		cout << "0" << ansh << ":" << "0" << ansm;
	}
	else if(ansm>=10)
	{
		cout << "0" << ansh << ":" << ansm;
	}
    }
    else if(ansh>=10)
    {
    if(ansm<10)
	{
		cout <<  ansh << ":" << "0" << ansm;
	}
	if(ansm>=10)
	{
		cout << ansh << ":"  << ansm;
	}
	}
}
