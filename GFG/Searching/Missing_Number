#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int t, x;
	cin>>t;
	while(t--)
	{
		int n,res=0;
		cin >> n;

		for(int i=1;i<n;i++){
			cin >> x;
			res = res^x;
			res = res^i;
		}
		cout<<(res^n)<<endl;
	}
	return 0;
}
