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

	int dp[x+1]={0};
	dp[0]=1;
	
	for(int i=0;i<n;i++){
		for(int j=1;j<=x;j++){
			if(j>=a[i])dp[j]=(dp[j]+dp[j-a[i]])%1000000007;
		}
	}
	cout<<dp[x];
	
	return 0;
}