#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define mod ((int)(1e9)+7)


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n, m; 
	cin>>n>>m;

	int a[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];

	int dp[n+1][m+2];
	memset(dp, 0, sizeof(dp));

	if(a[1]==0){
		for(int j=1;j<=m;j++)dp[1][j]=1;
	}
	else{ 
		dp[1][a[1]]=1;
	}
	for(int i=2;i<=n;i++){
		if(a[i]!=0){
			dp[i][a[i]]=(dp[i-1][a[i]]+dp[i-1][a[i]-1]+dp[i-1][a[i]+1])%mod;
		}else{
			for(int j=1;j<=m;j++){
				dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]+dp[i-1][j+1])%mod;
			}
		}
	}
	int ans=0;
	if(a[n]==0){
		for(int i=1;i<=m;i++){
			ans=(ans+dp[n][i])%mod;
		}
	}else{
		ans=dp[n][a[n]];
	}
	
	cout<<ans;
	
	return 0;
}