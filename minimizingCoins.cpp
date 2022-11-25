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
	int a[n]; 
	for(int i=0;i<n;i++)cin>>a[i];

	vector<int> dp(x+1, INT_MAX);

	dp[0]=0;
	for(int i=1;i<=x;i++){
		for(int j=0;j<n;j++){
			if(i>=a[j])
				dp[i]=min(dp[i], dp[i-a[j]]+1);
		}
	}
	if(dp[x]==INT_MAX)dp[x]=-1;
	cout<<dp[x];
	
	return 0;
}