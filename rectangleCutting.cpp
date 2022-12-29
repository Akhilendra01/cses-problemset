/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"


int dp[501][501];

int f(int l, int b){
	if(l<0 or b<0)return INT_MAX;
	if(l==b)return 0;

	if(dp[l][b]!=-1)return dp[l][b];

	int ans=INT_MAX;

	for(int i=1;i<l;i++){
		ans=min(ans, 1+f(l-i, b)+f(i, b));
	}
	for(int i=1;i<b;i++){
		ans=min(ans, 1+f(l, b-i)+f(l, i));
	}

	return dp[l][b]=dp[b][l]=ans;
}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int a, B; cin>>a>>B;

	memset(dp, -1, sizeof(dp));
	cout<<f(a, b);
	
	return 0;
}