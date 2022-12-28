#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n, x; cin>>n>>x;
	int a[n], price[n];
	
	for(int i=0;i<n;i++)cin>>price[i];
	for(int i=0;i<n;i++)cin>>a[i];

	int dp[2][x+1];
	memset(dp, 0, sizeof(dp));

	for(int i=1;i<=n;i++){
		for(int j=1;j<=x;j++){
			if(j>=price[i-1])dp[1][j]=max(dp[0][j], dp[0][j-price[i-1]]+a[i-1]);
			else dp[1][j]=dp[0][j];
		}

		for(int j=0;j<=x;j++)dp[0][j]=dp[1][j];
	}	

	cout<<dp[1][x];

	return 0;
}