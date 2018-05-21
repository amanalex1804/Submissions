#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define sz 10005
#define INF 99999999LL
int n1,n2;
ll A[sz],B[sz];
ll dp[sz][3];

ll rek(int ind,int cur){
	
	if(cur==0 and ind>=n2) return 0;
	if(cur==1 and ind>=n1) return 0;
	
	if(dp[ind][cur]!=-1) return dp[ind][cur];
	ll t1=-INF;
	if(cur==1){
		
		ll r1=rek(ind+1,cur)+A[ind];
		t1=max(t1,r1);
		
		int ind1=lower_bound(B,B+n2,A[ind])-B;
		if(ind1<n2 and B[ind1]==A[ind]){
			ll r2=rek(ind1+1,0)+A[ind];
			t1=max(t1,r2);
		}
		
	}
	
	else if(cur==0){
		  
		  ll r1=rek(ind+1,cur)+B[ind];
		  t1=max(t1,r1);
		  int ind1=lower_bound(A,A+n1,B[ind])-A;
		  if(ind1<n1 and A[ind1]==B[ind]){
		  	ll r2=rek(ind1+1,1)+B[ind];
		  	t1=max(t1,r2);
		  }
		
	}
	
	dp[ind][cur]=t1;
	return t1;
	
	
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	
	
	while(1){
		cin>>n1;
		if(!n1) break;
		for(int i=0;i<n1;++i) cin>>A[i];
		cin>>n2;
		for(int i=0;i<n2;++i) cin>>B[i];
		
		for(int i=0;i<max(n1,n2)+4;++i)
		for(int j=0;j<=2;++j)
		dp[i][j]=-1;
		
		ll ans1=rek(0,0);
		
			
	//	for(int i=0;i<max(n1,n2)+4;++i)
	//	for(int j=0;j<=2;++j)
	//	dp[i][j]=-1;
		
		ll ans2=rek(0,1);
		
		
		
		cout<<(ll)max(ans1,ans2)<<"\n";
		
		
		
		
	}
	
	
	
	return 0;
}
