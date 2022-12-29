/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"


int dp[501][501];

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int a, B; cin>>a>>B;

	for(int l=1;l<=a;l++){
		for(int b=1;b<=B;b++){
			if(l==b)continue;

			int ans=INT_MAX;

			for(int i=1;i<l;i++){
				ans=min(ans, 1+dp[l-i][b]+dp[i][b]);
			}
			for(int i=1;i<b;i++){
				ans=min(ans, 1+dp[l][b-i]+dp[l][i]);
			}
			dp[l][b]=dp[b][l]=ans;
		}
	}

	cout<<dp[a][B];
	
	return 0;
}