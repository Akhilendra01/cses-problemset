#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define mod 1000000007

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;

	char a[n+1][n+1];
	int dp[n+1][n+1];

	memset(dp, 0, sizeof(dp));
	dp[1][1]=1;
	if(a[1][1]=='*')dp[1][1]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)cin>>a[i][j];
		
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i-1][j]!='*')dp[i][j]+=dp[i-1][j];
			if(a[i][j-1]!='*')dp[i][j]+=dp[i][j-1];
			dp[i][j]%=mod;
		}
	}
	if(a[n][n]=='*')dp[n][n]=0;
	
	cout<<dp[n][n];

	return 0;
}