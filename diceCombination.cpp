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

	int n; cin>>n;
	int dp[n+1];
	dp[0]=1;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+(i>=2?dp[i-2]:0)+(i>=3?dp[i-3]:0)+(i>=4?dp[i-4]:0)+(i>=5?dp[i-5]:0)+(i>=6?dp[i-6]:0);
		dp[i]%=1000000007;
	}
	cout<<dp[n];
	
	return 0;
}